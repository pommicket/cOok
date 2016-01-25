# cOok
An Ook! compiler

As a reminder, ook is just [Brainf\*\*\*](https://esolangs.org/wiki/Brainfuck), but with these rules:  
Ook&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Brainf\*\*\*  
Ook. Ook?    >  
Ook? Ook.    <  
Ook. Ook.    +  
Ook! Ook!    -  
Ook! Ook.    .  
Ook. Ook!    ,  
Ook! Ook?    [  
Ook? Ook!    ]  

**You can write a comment anywhere, as long as it doesn't have periods, commas, or exclamation marks.**

# Windows

The file extension of the file must be exactly 3 letters. A recommended file extension is *.ook.
To compile ook, `cd` to the directory where cOok is installed, then run:
```
cd build/Windows
cook <file>
```

# GNU/Linux
The file extension of the file must be exactly 3 letters. A recommended file extension is *.ook.
To compile ook, `cd` to the directory where cOok is installed, then run:
```
cd build/GNULinux
./cook <file>
```
You can also add cook to /usr/bin so that it's in your path.
```
sudo cp build/GNULinux
```
Then you can just run:
```
cook <file>
```
Anywhere


If you want to compile the source, just run:
```
make
```
in the source directory.
