# Getting Started with Helix Device Cloud (HDC) #
<cr>

## Overview ##
Wind River® Helix™ Device Cloud is a device management platform for the Internet of Things (IoT) that helps organizations greatly reduce the complexities of building and operating large-scale device deployments.  Specifically, it is the management conosle that Wind River uses to manage their Wind River Linux operating system that the Intel IoT Gateway is based on.

## Required Hardware ##
-   IoT Gateway that uses Intel® IoT Gateway Technology

## Assumptions ##
-   [Intel® IoT Gateway Technology version 3.1](https://shopiotmarketplace.com/iot/index.html#/details?pix=58) or above
-   An internet connection to the gateway that has the ability to talk to the HDC cloud

## Getting Access to HDC ##
Prior to configuring your gateway to connect to Helix Device Cloud, it is necessary to get a trial account.  You can do that by clicking the contact  us link on this site:
[http://www.windriver.com/products/helix/device-cloud/](http://www.windriver.com/products/helix/device-cloud/)

## Installing the HDC Agent ##
Download the HDC 2.1 agent from here:
[intel-iot-gateway/Getting Started With Helix Device Cloud (HDC)/hdc/](https://github.com/intel-iot-devkit/intel-iot-gateway/blob/master/Getting%20Started%20With%20Helix%20Device%20Cloud%20(HDC)/hdc/HDC21forIDP31.tgz)

Connect to the Developer Hub on the IoT gateway, click on the Administration tab and Launch Cloud Commander. If you need a more in depth tutorial on how to use Cloud Commander, please refer to the that [tutorial](https://github.com/intel-iot-devkit/Intel-IoT-Gateway/tree/master/Getting Started With Cloud Commander).

![](images/image1.png)

Copy the HDC 2.1 agent files to the gateway by positioning your windows so that you can drag the file on the file editor that you downloaded earlier and copy them to the IoT gateway.

![](images/image2.png)

Then extract it:

![](images/image3.png)

Then launch the built in command interface in cloud commander:

![](images/image4.png)

Run the following commands:

cd /root

rpm -ihv *.rpm
 
![](images/image5.png)

The agent is now installed, however you need to configure the startup.bin file to point you your instance of HDC.  It is critical that you do this now, before you reboot so that you don’t connect to the wrong instance.

Open your HDC instance from the link in the email below and go to your profile settings:

![](images/image6.png)

Download the startup.bin file to your local machine.
Go back to the Developer Hub interface and copy over the startup.bin file into the /opt/intel/ubroker/bin/ directory, overwriting what is already there if that file is already present.

![](images/image7.png)

Now reboot your gateway and log back into your HDC console.  You should now see the gateway listed in HDC.

*indicates that third-party names might be the property of others.