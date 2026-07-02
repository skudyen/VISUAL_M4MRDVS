----------[ START GUIDE ]----------

install 
    cd CameraSDK/linux
    source install.sh
## want test 

Config Ip
    Camera IP subnet is 192.168.100.*. [On host Computer]
    subnet mask is 255.255.255.0

Install OpenCV
    sudo apt-get install libopencv-dev
    sudo apt-get install libpcl-dev

    sudo sh ./install.sh
    cd /opt/
    ll | grep lanxin

Step 1 : CMake
    cmake -S . -B build
    cmake --build build
    LD_LIBRARY_PATH=CameraSDK/linux/SDK/lib/linux_x64 ./build/bin/VISUAL_CamPROG_Proto

Clean step : 
    rm -rf build

----------[ Test File ]----------

Note : requires the SDK to be installed to /opt/MRDVS first
    ./CameraSDK/linux/install.sh

Step 1 : CMake
    cmake -S test/C -B build_test
    cmake --build build_test
    ./build_test/bin/demo_<name>      # e.g. demo_single_camera2, demo_multi_cameras, ...

Clean step : 
    rm -rf build_test

## https://github.com/Lanxin-MRDVS/MRDVS-wiki/blob/main/Depalletizing-algorithm-deployment.md