#include <AnalizerImpl.h>

void AnalizerImpl::setCountDirectory(size_t inputCountDirectory)
{
    countDirectory = inputCountDirectory;
}

void AnalizerImpl::setPathToResult(const std::string &inputPathToResult)
{
    pathToResult = inputPathToResult;
}

void AnalizerImpl::setPathToData(const std::string &inputPathToData)
{
    pathToData = inputPathToData;
}

std::string cutName(std::string path)
{
    std::string answ;
    for (int i = path.size() - 1; i >= 0; --i)
    {
        if (path[i] == '/')
        {
            break;
        }
        answ += path[i];
    }
    std::reverse(answ.begin(), answ.end());
    return answ;
}

#include <iostream>

std::vector<Group> AnalizerImpl::categorize()
{
    DirHandler directory(pathToData);
    std::vector<FileInfo> filesInfo = directory.getFiles();

    std::cout << std::endl;
    for (auto &fileInfo : filesInfo)
    {
        std::cout << fileInfo.getPath() << ": ";
        for (const auto &[word, count] : fileInfo.getAllMetric())
        {
            std::cout << "[" << word << "," << count << "] ";
        }
        std::cout << ";" << std::endl;
    }
    std::cout << std::endl;

    TFIDFPP tfidf(filesInfo);
    std::set<std::string> setUnicWords = tfidf.getSetUsefulUnicWords();
    std::cout << " > " << setUnicWords.size() << std::endl;

    std::cout << std::endl;
    for (auto &elem : setUnicWords)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    for (auto &elem : tfidf.getSetUnicWords())
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::vector<VectorSpace<double>> vectorsSpace;
    std::vector<VectorSpace<double>> vectorsCentroids;
    for (auto &fileInfo : filesInfo)
    {
        vectorsSpace.emplace_back(setUnicWords.size());
        size_t i = 0;
        for (auto &word : setUnicWords)
        {
            vectorsSpace.back()[i++] = tfidf.calculateTFIDFMetric(word, fileInfo.getPath());
        }
        if (pathsToCentroids.find(fileInfo.getPath()) != pathsToCentroids.end())
        {
            vectorsCentroids.push_back(vectorsSpace.back());
        }
    }
    KMeans<VectorSpace<double>> kMeans(vectorsSpace);
    std::vector<Cluster> clusters = kMeans.calculate(countDirectory, vectorsCentroids);

    std::vector<std::string> allPath;
    for (auto &fileInfo : filesInfo)
    {
        allPath.push_back(fileInfo.getPath());
    }
    std::vector<std::vector<std::string>> clusteringData;
    for (auto &cluster : clusters)
    {
        clusteringData.push_back(cluster.getClusteringDataByData(allPath));
    }
    std::vector<Group> result;
    size_t count = 0;
    for (const auto &group : clusteringData)
    {
        if (group.empty())
        {
            continue;
        }
        Group tempGroup;
        for (const auto &filename : group)
        {
            tempGroup.addFile(filename);
        }
        result.push_back(tempGroup);
        result[count].setGroupName("group_" + std::to_string(count));
        ++count;
    }
    return result;
}

void AnalizerImpl::move()
{
    FileManager mover;
    std::vector<Group> groups = categorize();
    for (const auto &group : groups)
    {
        mover.createDir(pathToResult + "/" + group.getGroupName());
        for (auto filename : group.getFiles())
        {
            mover.moveFile(filename, pathToResult + "/" + group.getGroupName() + "/" + cutName(filename));
        }
    }
}

void AnalizerImpl::analize()
{
    move();
}

void AnalizerImpl::setPathsToCentroids(const std::vector<std::string> &inputPathsToCentroids)
{
    pathsToCentroids.clear();
    for (const auto &pathToCentroid : inputPathsToCentroids)
    {
        pathsToCentroids.insert(pathToCentroid);
    }
}