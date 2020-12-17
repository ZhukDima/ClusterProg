import os

os.mkdir('test_files')
lorem = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
data = lorem.split(' ')
for i in range(30, 70):
    f = open('test_files/' + str(i) + '.txt', 'w')
    f.write(' '.join(data[t] for t in range(i)))
    f.write('\n')
    f.close()
queen = 'Buddy, you\'re a boy, make a big noise \
Playing in the street, gonna be a big man someday \
You got mud on your face, you big disgrace \
Kicking your can all over the place, singin\' \
\
We will, we will rock you \
We will, we will rock you \
\
Buddy, you\'re a young man, hard man \
Shouting in the street, gonna take on the world someday \
You got blood on your face, you big disgrace \
Waving your banner all over the place \
\
We will, we will rock you, sing it! \
We will, we will rock you, \
\
Buddy, you\'re an old man, poor man \
Pleading with your eyes, gonna get you some peace someday \
You got mud on your face, big disgrace \
Somebody better put you back into your place, \
\
We will, we will rock you, sing it! \
We will, we will rock you, everybody \
We will, we will rock you, \
We will, we will rock you, \
Alright'
data = queen.split(' ')
for i in range(30, 70):
    f = open('test_files/' + str(100 + i) + '.txt', 'w')
    f.write(' '.join(data[t] for t in range(i + 50)))
    f.write('\n')
    f.close()

