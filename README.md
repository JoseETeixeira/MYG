# MYG


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


# OPEN CV
https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html


const float verts[] = {
            posX, posY,
            posX + spriteWidth, posY,
            posX + spriteWidth, posY + spriteHeight,
            posX, posY + spriteHeight
        };
        const float tw = float(spriteWidth) / texWidth;
        const float th = float(spriteHeight) / texHeight;
        const int numPerRow = texWidth / spriteWidth;
        const float tx = (frameIndex % numPerRow) * tw;
        const float ty = (frameIndex / numPerRow + 1) * th;
        const float texVerts[] = {
            tx, ty,
            tx + tw, ty,
            tx + tw, ty + th,
            tx, ty + th
        };

        // ... Bind the texture, enable the proper arrays

        glVertexPointer(2, GL_FLOAT, verts);
        glTexCoordPointer(2, GL_FLOAT, texVerts);
        glDrawArrays(GL_TRI_STRIP, 0, 4);