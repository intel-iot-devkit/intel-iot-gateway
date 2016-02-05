# Getting Started With Cloud Commander #
<cr>

## Overview ##
Cloud Commander is a web based file manager with console and editor. Using Cloud Commander, you can work with files, directories and programs via your  browser from any computer, mobile or tablet.  It's a quick and easy way to take an application you've developed locally, upload it to your gateway, and test, edit, iterate directly from the Intel IoT Gateway Developer Hub interface on your Intel Internet of Things Gateway.

## Required Hardware ##
-   Intel Internet of Things Gateway
-   A system running a web browser.  IN the case of this tutorial, we used a laptop running Windows 10 and Chrome.

## Assumptions ##
-   Intel Internet of Things Gateway is running version 3.1 or above
-   Cloud Commander is enabled (installed and enabled by default)
-   You have network connectivity to the Intel Internet of Things Gateway and you know it's IP address

## Access Cloud Commander ##
Cloud Commander is all web based and can be easily accessed via the Intel IoT Gateway Developer Hub.  To access the Developer Hub, open your web browser and go the <http://ipaddressofthegateway>. Log in with the username and & password.  Once connected, you should see something like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Cloud%20Commander/images/image1.png)

To access Cloud Commander, click on the Administration Icon.  You should see a screen like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Cloud%20Commander/images/image2.png)

Now click on the LAUNCH button under the Folder icon.  This will open Cloud Commander.  You should now see two sections showing the folder listing on your gateway.  Below the folder listings are a row of buttons (you may need to scroll down). It will look like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Cloud%20Commander/images/image3.png)

This is Cloud Commander.  From here you can navigate to any folder or file on your gateway just by clicking on the folder name.  Here are the primary features of Cloud Commander. You can click on these buttons or press the corresponding function key

- F1 Opens a Help screen
- F2 Renames a file
- F3 Views a file
- F4 Edits a file
- F5 Copies a file.  You will be prompted for the location to copy to. By default it will be whatever location you are in on the right side file / folder browser.
- F6 Moves a file.You will be prompted for the location to copy to. By default it will be whatever location you are in on the right side file / folder browser.
- F7 Create a new folder
- F8 Delete a file (you will be prompted to confirm)
- F9 Opens a menu of these options including extras such as Pack and Extract which uses Tar).  You can also open this menu or a subset by right clicking on a file, folder, or blank space.
- F10 Opens a settings menu for Cloud Commander
- >_~ Opens a web based terminal to your gateway.  Very powerful way to quickly execute a command or commands directly on your gateway from the web browser 

To copy files to/from your local system, just drag them to/from the Cloud Commander interface.  You can also right click in Cloud Commander and choose Upload or right click on a file in Cloud Command and choose download.  By right clicking, you'll also see Upload to Cloud or Upload From Cloud.  This is just like coping to/from your local system but supports directly accessing common cloud locations such as Dropbox, Google Drive, Box, and Amazon Cloud.

Let's walk though a typical scenario of using Cloud Commander.

Say you've developed an python application you now want to run from your gateway.  Here's a quick sample.  Save this to a local file on your system and name it hello-world.py

```

	printx "Hello World"
```

Open up Cloud Commander, navigate to your /home/gwuser folder.
Now let's copy the hello-world.py application to you gateway.  Simple drag it from your system to the Cloud Commander view of the /home/gwuser folder.

Now that's it on your gateway, let's try running it.

From Cloud Commander, click on the >_~ button to open a terminal session.  Enter these commands to change to your home folder and run the application

> cd /home/gwuser
> python hellow-world.py

Opps, it looks like there's an error with our code.

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Cloud%20Commander/images/image4.png)

Close the terminal session by clicking the X in the top right of the window and from Cloud Commander click on the hello-world.py file and choose or click on the F4 button to edit the file.

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Cloud%20Commander/images/image5.png)

Ah, it looks like there's a typo.  Remove the "x" after "print" and click on the X in the top right of the window to close the file and confirm that you want to save your changes.

Now let's try the applicaiton again.  From Cloud Commander, click on the >_~ button to open a terminal session.  Enter these commands to change to your home folder and run the application

> cd /home/gwuser
> python hellow-world.py

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Cloud%20Commander/images/image6.png)

Much better.  Now the applicaiton runs correctly.

**Congratulations! You've successfully used Cloud Commander to upload, edit, and execute an application on the Intel IoT Gateway.**

## References ##
-   [Cloud Commander](http://cloudcmd.io)