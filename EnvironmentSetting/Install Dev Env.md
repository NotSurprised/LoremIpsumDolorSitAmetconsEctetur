# Install Dev Env

###### tags: `else`

### Install doxygen to generate the project doc
```shell
sudo apt install doxygen
```

### Install GoogleTest
```shell
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake -DBUILD_GTEST=ON -DBUILD_GMOCK=ON -DINSTALL_GTEST=ON -DINSTALL_GMOCK=ON ../
sudo make install
cd ~
```

### Install JSON-C
```shell
git clone https://github.com/json-c/json-c.git
cd json-c
mkdir build
cd build
cmake ../
make
sudo make install
cd ~
```