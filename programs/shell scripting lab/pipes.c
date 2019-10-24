1.$who|tee /dev/tty|wc -l
2.$ls|tee /dev/tty|grep poem|wc -l|cat>file1.txt
3.$ cat file1.txt file2.txt|tee /dev/tty|cat file3.txt
4.$ls|grep poem|tee /dev/tty|wc -l
5.$read city| cat>>cityfile.txt|sort|cat>newcity.txt
6.$
7.$ls|grep p*|tee /dev/tty|cat>file1.txt
8.$ls|grep p*|tee /dev/tty| /dev/tty
9.sort a.txt b.txt c.txt|/dev/tty
10.$ls|tail --lines=20|tee /dev/tty|cat>profile.txt