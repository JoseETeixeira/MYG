# MYG

The evolution of B.Y.O.N.D, rewritten in C++ and OpenGL3. 

The project will at some point become private, or migrate to another repository when server functionality is added for security purposes. For now, it features

- DME reader/parser
- DMM reader/parser 
- Code editor interface


## Compiling


- UBUNTU

Install GLAD 

```
pip install glad
sudo apt-get install zlib1g-dev
sudo apt-get install libpng-dev
cd third_party/boost 
./bootstrap.sh 
./b2 install --prefix=/usr/share/Boost

```


Windows

```
pip install glad
cd third_party/boost 
./bootstrap.bat 
./b2 install --prefix=C:\boost

```

## TUTORIALS

- https://learnopengl.com/Getting-started/Creating-a-window
- https://www.youtube.com/watch?v=0U-9ofLB22E
- https://github.com/factorsofx/DMEdit/blob/master/editor/src/main/java/com/factorsofx/dmedit/editor/ui/view/tree/ObjectTreeTreeModel.java


- C# from C++
-https://stackoverflow.com/questions/778590/calling-c-sharp-code-from-c/778677

- DMI READER 

https://github.com/bobbahbrown/DMISharp/blob/master/DMISharp/DMIFile.cs

