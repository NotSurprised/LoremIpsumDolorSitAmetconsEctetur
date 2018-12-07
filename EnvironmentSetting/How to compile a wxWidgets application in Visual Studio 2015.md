# How to compile a wxWidgets application in Visual Studio 2015?
November 26, 2018, 9:27 pm	by NotSurprised modified from Rhyous

## Step 1 – Install Visual Studio 2015
1. If you don’t have it, get the express edition here: http://www.microsoft.com/Express/VC/
1. Run through the installer, not much else to do.

## Step 2 – Install wxWidgets
1. Download wxWidgets (select the wxMSW installer file) from here:
1. http://www.wxwidgets.org/downloads/
1. I choose to install to `c:\wxWidgets-3.1.0` but you can choose a different path if you want. I choose v3.1.0, cuz 3.1.1 always come out with problem when I try to compile the new project.

## Step 3 – Compile the wxWidgets Libraries.
1. Grab the sources.
1. Unpack the sources.
1. Open VS IDE.
1. Open `\build\msw\wx-vc14.sln` (adjust as necessary.)
1. Go to "Build->Batch Build...", click "Select All", "Build".
1. Go drink some coffee or watch TV.
1. After the build finishes, open `wxWidgets/samples/minimal/minimal_vc14.sln`.
1. Let MSVC convert the solution to become an appropriate format.
1. Build and run the sample.

## Step 4 – Create a new project
1. In Visual Studio 2015, go to File | New Project.
![](https://i.imgur.com/cLY2l0i.png)
3. Select Visual C++ | Empty Project.
![](https://i.imgur.com/1tq3b2H.png)
5. Give the project a name and click OK. I named this `wxGUI`.

## Step 5 – Create/Copy your source to this project.

1. Right-click on the Project name and choose Open Folder in Windows Explorer. This will open to the home folder of your project. (Don’t right click the Solution name, make sure to right click the project under the solution name.)
1. Open a second Windows Explore window.
1. In the second window, browse to the wxWidgets sample directory and open the Minimal folder: `C:\wxWidgets-3.1.0\samples\Minimal\minimal.cpp` && `C:\wxWidgets-3.1.0\samples\sample.***`
`Note: You can choose other projects but you may want to start with Minimal and move on from there.`
1. Copy only the `minimal.cpp` and `sample.***` files to your project directory (the rest are not needed).
1. Close the second window pointing to the `C:\wxWidgets-3.1.0\samples\Minimal` directory, it is not needed anymore.
1. From the explorer window open to your project directory, use ctrl+click to highlight both the `minimal.cpp` and `sample.rc` files.
1. Drag both highlighted files into the Visual Studio Window and drop them over the project name.
1. The `minimal.cpp` file should automatically be placed under the Source files section of your project.
1. The `sample.rc` file should automatically be placed under the Resource files section of your project. `sample.rc` will load other `sample.***` resource.

## Step 7 – Customize the project properties
1. Right-click on the `wxGUI` project and select Properties. (Don’t right click the Solution name, make sure to right click the project name child under the solution name.)
1. In the top left of the properties window there is a Configuration drop down menu. Select All Configurations. And Plateform: `x64`.
1. Click to expand Configuration Properties.
1. Click to `VC++ Directories`.

1. Enter the following in Include Directories.
```
..\external_include\wxWidget\msvc;
..\external_include\wxWidget;
..\external_include\libpthread;
..\external_include\libevent;
..\external_include\libws;
..\external_include\libpcre;
..\external_include\;
.\windows;
.;
$(IncludePath);
$(VC_IncludePath);
$(WindowsSDK_IncludePath);
```
![](https://i.imgur.com/O0RjJX8.png)

1. Enter the following in Include Directories.
```
..\external_include\wxWidget\lib\vc_x64_lib;
$(VC_LibraryPath_x64);$(WindowsSDK_LibraryPath_x64);
$(NETFXKitsDir)Lib\um\x64;
$(LibraryPath)
```
![](https://i.imgur.com/NFk9vap.png)


# Error
![](https://i.imgur.com/tKLMROW.png)

![](https://i.imgur.com/79zWj0Q.png)

![](https://i.imgur.com/QhjuXyu.png)

![](https://i.imgur.com/nvB2pd6.png)
