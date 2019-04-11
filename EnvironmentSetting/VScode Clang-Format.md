# VScode Clang-Format

1. Install Node.js & npm
```shell
sudo apt install nodejs
sudo apt install nodejs-dev node-gyp libssl1.0-dev
sudo apt install npm
sudo npm install -g clang-format
```
Let npm to take control `PATH`.

2. Download & Install VScode
3. Install extension `Clan-Format` in VScode
4. Setting extension in VScode setting
Setting configuration in vscode settings.json file 
```JSON
{
    "editor.formatOnSave": true
    
    "clang-format.executable": "/absolute/path/to/clang-format"
}
```
Or use GUI
![](https://i.imgur.com/FbnxPvo.png)

![](https://i.imgur.com/Xl04JJW.png)

You can find `/absolute/path/to/clang-format` by typing `whereis clang-format`

![](https://i.imgur.com/CIQ3ppv.png)

5. Create a new file `.clang-format` in project dir
```
BasedOnStyle:    LLVM
Language:        Cpp
ColumnLimit:     100
```
6. restart VScode
7. Find your favorite format template & customize on your own
https://clang.llvm.org/docs/ClangFormatStyleOptions.html#
```
BasedOnStyle:              Mozilla
BreakBeforeBraces:         'Custom'
BraceWrapping: {
    AfterClass:            'false'
    AfterFunction :        'false'
    BeforeCatch :          'false'
    IndentBraces :         'false'
}
ColumnLimit:               100
Language:                  JavaScript
MaxEmptyLinesToKeep:       1
JavaScriptQuotes:          Single
SpacesInContainerLiterals: false
```