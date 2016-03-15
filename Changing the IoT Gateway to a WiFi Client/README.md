# Changing the IoT Gateway to a WiFi Client #
<cr>

## STOP! ##
This process is a work in progress.  Do not attempt unless you actively working with a customer support representative or are prepared to rebuild your IoT Gateway if something goes wrong.

## Overview ##
By default, the your IoT Gateway that uses Intel® IoT Gateway Technology comes pre-configured setup as a WiFi Access Point.  This is so you can connect a client to it access it for initial evaluation and later configuration without connecting it to a wired network.  If you want to connect the IoT Gateway to a WiFi network, you'll need to change it's network configuration from an Access Point to a client.  This can be easily done via the administration portal acceded from the Intel® IoT Gateway Developer Hub.

## Required Hardware ##
-   IoT Gateway that uses Intel® IoT Gateway Technology
-   A system running a web browser.  In the case of this tutorial, we used a laptop running Windows 10 and Chrome.

## Assumptions ##
-   Intel® IoT Gateway Technology version 3.1 or above
-   You have wired network connectivity to the IoT Gateway and you know it's IP address

## Warning ##
It is highly recommenced you connect the IoT Gatway to a wired network and use that connection for this process.  It is possible to make these changes via the wireless connection as long as you only save changes, but not apply them, until the last step; but if you make any mistakes or if it doesn't connect to your WiFi network for some reason, you may not longer be able to access the gateway.  If this happens, see the Restoring factory network setting section below.  

## Configuration Changes ##

Ensure the IoT Gateway is plugged in to a wired network connection.  If the IoT Gateway has multiple Ethernet ports, you should use the one that corresponds to eth0.  You'll need to know the IP address of this wired connection.  You can use one of these methods to obtain the IP address.

- If your client is wirelessly connect to the gateway directly, you can obtain the IP addresses through the Developer Hub main screen where gateway information is shown on the left side.
- Access a console by a directly connected monitor & keyboard or by launching Cloud Commander from the Administration tab on the Developer Hub.  To do so, click on the Launch button under the folder icon.  once in Cloud Commander click on the >_~ icon to open a console.  Then enter:

	> ifconfig
	
	Look for the inet addr: within the eth0 section

Once you know the IP address of the wired connection, close any instances you have to the Developer Hub, connect your client to the same network that the IoT gateway's wired connection is connected to, and reconnect to the Developer Hub by going to:
http://wiredipaddressofthegateway

After logging in, you should see a screen like this

![](images/image1.png)

To access the IoT Gateway Admin console, click on the Administration Icon.  You should see a screen like this:

![](images/image2.png)

Now click on the LAUNCH button under the Gear icon.  This will open another browser window or tab.  Log in with your root password.  It will look like this:

![](images/image2.png)

This is the admin console for the gateway.  From here you can manage and configure many gateway settings but we'll be focusing on the network section.

1. Click on Network from the menu bar and select Interfaces
2. To the right of the 1st Network section (currently configured as LAN and br-lan), click on Edit
3. Click on Physical Settings
4. Uncheck Bridge interface
5. Click on Save (not Save & Apply)
6. Click on Firewall Settings
7. Select wan
8. Click on Save (not Save & Apply)
9. Click on Network from the menu bar and select WiFi
10. Click on Edit
11. Click on Mode and change it from Access Point to Client
12. In the ESSID filed, enter the SSID of the WiFi network you want to connect the IoT Gateway to.
13. Click on the Wireless Security Tab
14. Set the encryption type to match the WiFi network you are connecting to
15. Set the key for the WiFi network you are connecting to 
16. Click on Save & Apply
17. It will take a few moments for the new configuration to apply

You can confirm you are now connected to your WiFi network by again issuing an ifconfig command on the IoT Gateway console.  You should see an IP address assigned to wlan0.  If not, recheck your SSID and encryption settings.

Note the IP address assigned to WLAN0.  

Using the same administrative interface you used above, click on System and Reboot. Click on Perform reboot

Now unplug the wired Ethernet connection.

After the IoT Gateway reboots, reconnect to the Developer Hub via the WLAN IP address you noted above (This assumes your client is on the same network or can route to it).

**Congratulations! You've successfully changed the IoT Gateway to WiFi Client mode and connected to your network.**

## Using the wired connection as well ##

Connect to the Developer Hub by going to:
http://wirelessipaddressofthegateway  

Click on the Administration icon

Now click on the LAUNCH button under the Gear icon.  This will open another browser window or tab.  Log in with your root password.  

This is the admin console for the gateway.  From here you can manage and configure many gateway settings but we'll be focusing on the network section.

1. Click on Network from the menu bar and select Interfaces
2. To the right of the 2nd Network section (currently configured as WAN and eth0), click on Edit
6. Click on Firewall Settings
7. Select lan
8. Click on Save & Apply

If you plug a wired connection to to Eth0, you sound now be able to reach the IoT Gateway via the address assigned to that connection. You can use the ifconfig command mentioned above to obtain the IP address.  If you wan to set a static IP address, please refer to the next section.

## Using static IP addresses ##

Connect to the Developer Hub by going to:
http://wirelessipaddressofthegateway  

Click on the Administration icon

Now click on the LAUNCH button under the Gear icon.  This will open another browser window or tab.  Log in with your root password.  

This is the admin console for the gateway.  From here you can manage and configure many gateway settings but we'll be focusing on the network section.

1. Click on the Edit button for the interface you want to change to a static IP address
2. Select the Protocol drop down and change it to Static address
3. Click on Switch protocol
4. Enter the IP address and associated netmask, gateway, and DNS server
5. Click on Save & Apply
	1. WARNING, you are changing the IP address of interface you are using to access the IoT Gateway you will need to change your URL to the new address after Clicking on Save & Apply.

## Restoring factory network settings ##
These links provide the default [network](images/network) and [wireless](images/wireless) config files.  If through a configuration error the gateway becomes inaccessible, you can place these files on a USB flash drive and copy them to the gateway using a directly connected monitor and keyboard.  Both files need to be copied in to the /etc/config folder.  Placing them there and rebooting will return the network configuration to the default settings; (with one exception. The SSID will be "IDPDK-4001" and not IDPDK-lastfourofyourmacaddress).

## References ##
-   none


*indicates that third-party names might be the property of others.