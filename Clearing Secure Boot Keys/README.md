# Clearing Secure Boot Keys from the BIOS #
<cr>

## Overview ##
When an IoT Gateway that uses Intel® IoT Gateway Technology is installed, the secure boot keys in the BIOS are set to match the keys used to sign the kernel.  Once this is done, images that do not match will not boot on the HW.  This prevents booting an alternative image/os and gaining access to the data on the IoT Gateway.  If you need to install a new image with non-default keys, you will first need to clear the secure boot keys from the BIOS. 

## Required Hardware ##
-   IoT Gateway that uses Intel® IoT Gateway Technology

## Assumptions ##
-   Intel® IoT Gateway Technology version 3.1 or above

## Clearing the Keys ##

1.	Boot/reboot the Gateway.
2.	Select boot device by pressing F12 before boot or ESC to enter BIOS (depends on HW).
3.	Select Enter Setup (skip if ESC entered BIOS).
4.	Select the Security Menu.
5.	Select Secure Boot Menu.
6.	Set Secure Boot to Disabled.
7.	Press F4 to save and exit.
8.	System will reboot.
9.	Select boot device by pressing F12 before boot.
10.	Select Enter Setup.
11.	Select the Security Menu.
12.	Select Secure Boot Menu.
13.	Set Secure Boot to Enabled; accept the Warning - press enter to OK.
14.	Set Secure Boot Mode to Custom.
15.	Select Key Management.
16.	Set Default Key Provision to Disabled.
17.	Select Delete All Secure Boot Variables or for each Section (5) select Delete PK, KEK, DB, DBT, and DBX
a.	All should say NOT INSTALLED
18.	Press Esc.
19.	Set Secure Boot Mode to Standard.
20.	Ensure Secure Boot is set to Enabled.
21.	Press F4 to save and exit.

## Boot the System ##

1.	System will reboot.
2.	Select boot device by pressing F12 before boot.
3.	Select Enter Setup.
4.	Select the Security Menu.
5.	Select Secure Boot Menu.
	- System Mode should say Setup
	- Secure Boot should say Not Active
	- Secure Boot should say Enabled
	- Secure Boot Mode should say Standard
6.	Press F4 to save and exit.

You now can boot a new image.

## References ##
-   none

*indicates that third-party names might be the property of others.
