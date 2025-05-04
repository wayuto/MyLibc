echo "export LD_PATHS=$PWD/include/" >> ~/.zshrc
echo "export SO_PATHS=$PWD/so/libio.so:$PWD/so/libfile.so:$PWD/so/malloc.so:$PWD/so/syscall.so" >> ~/.zshrc
echo "export LD_PATHS=$PWD/include/" >> ~/.bashrc
echo "export SO_PATHS=$PWD/so/libio.so:$PWD/so/libfile.so:$PWD/so/malloc.so:$PWD/so/syscall.so" >> ~/.bashrc
gcc wcc.c -o wcc -static
sudo ln -s $PWD/wcc /usr/bin/wcc
