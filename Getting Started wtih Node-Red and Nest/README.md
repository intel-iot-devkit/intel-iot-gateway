# Getting Started with Node-Red and Nest #
<cr>

## Overview ##

Node-RED is a tool for wiring together hardware devices, APIs and online
services in new and interesting ways. Node-RED provides a browser-based
flow editor that makes it easy to wire together flows using the wide
range nodes in the palette. Flows can be then deployed to the runtime in
a single-click. The light-weight runtime is built on Node.js, taking
full advantage of its event-driven, non-blocking model. This makes it
ideal to run at the edge of the network. Turn it up, turn it down. The Nest Learning Thermostat remembers what temperatures you like, creates a custom schedule for your home, and turns itself down when you’re away. Once it’s learned your schedule, Nest can save 20% on your
heating and cooling bills. And if you want remote control, just use your smartphone, tablet or computer. Nest System Match optimizes controls for your heating and cooling system, while the Nest Leaf guides you to energy-efficient temperatures. With Energy History and Energy Report, you can see how much energy you’ve used and get tips to help you save more.

## Required Hardware ##

-   Intel Internet of Things Gateway

-   Nest Thermostat and optionally Nest Protect


> ![](images/image1.png)
> ![](images/image1.5.png)

## Assumptions ##

-   Intel Internet of Things Gateway is running version 3.1 or above

-   Node.js is installed on the Intel IoT Gateway (installed by default)

-   Node-red node node-red-contrib-nest is installed on the Intel IoT
    Gateway
	- You can install this package by clicking on Packages and then Add Packages from the Intel IoT Gateway Developer Hub interface
	
-   Node-Red is installed on the Intel IoT Gateway and is running(installed by default)
-   Nest products (Thermostat(s) and or Protect(s) are installed, functioning, and are connected to a Nest cloud account

Nest Developer Account Setup
==========================

You will need a Nest Developer Program account account to query your the Nest cloud for your Nest data.  

Create a [Nest developer portal](https://developer.nest.com/) account and log in.

Create a "Client Product"

- Give your product a unique name
- Choose which types of data you wish to make available for read and/or write (i.e. Thermostat, Away, Smoke+CO Alarm)
- Set the permissions to read/write accordingly.
- Set the Categories to Home Automation and Building for example.
- Set the users to Individual.
- The Support URL is a required field but not needed for this example.  Set it to something appropriate for you.
- Leave the Redirect URI blank to enable the PIN CODE authentication process
- Click on Create Product

Keep the web page open as you'll need the Product ID, Product Secret, Authorization URL, and Access Token URL information later.


Using Node-Red
==============

The Node-Red browser interface can be reached via
<http://ipaddressofthegateway:1880>. When it first comes up it will look
something like this.

![](images/image2.png)

Let’s create a node-red flow to get the badge readings from the RFID
reader.

Drag the following nodes from the left bar on to Sheet 1

-   Serial input

-   debug

Now, configure the nodes

-   Double click on the serial node. Click on the pen icon to add a new
    serial port. In the Serial Port field, enter the device you noted
    above when you plugged the RFID reader in to the Intel IoT Gateway.
    Likely /dev/ttyUSB0. Set the Baud Rate to 9600. Leave the other
    fields as default. For example:

> ![](images/image3.png)

-   Click on OK/Update

-   Set the name to “RFID In”. For example:

> ![](images/image4.png)

-   Click OK

-   Now wire the RFID In node to the Debug node by clicking and dragging
    between the small box on the right of the RFID In node to the small
    box on the left of the Debug node. It should look like this:

> ![](images/image5.png)

-   Click on the Deploy button, top right, and Confirm deploy.

-   Ensure the “debug” node is turned on. The box extending to the right
    of the node should be solid/filled in green.

-   Switch the column on the right from the Info tab to the debug tab.

-   Scan one of your badges.

    -   The badge ID should appear as part of the payload message in the
        debug tab.

-   Scan your other badge.

    -   The badge ID should appear as part of the payload message in the
        debug tab.

        Congratulations! You are successfully communicating via Serial
        to a RFID reader device.

Example flow
============

Node-Red supports exporting and importing of flows (into source json).
Here is an export of the above two flows we created. If you import this,
the same nodes and configuration we created manually will automatically
appear on the selected Sheet. Import and Export can be found in the
Node-Red menu by clicking on the 3 horizontal lines to the right of the
Deploy button.

```json
[{"id":"7bc6f0f3.84391","type":"serial-port","serialport":"/dev/ttyUSB0","serialbaud":"9600","databits":"8","parity":"none","stopbits":"1","newline":"\\n","bin":"false","out":"char","addchar":false},{"id":"b8d1dd75.472e2","type":"serial in","name":"RFID In","serial":"7bc6f0f3.84391","x":154,"y":376,"z":"d8bf240b.2740d8","wires":[["b9130dd8.46ecf"]]},{"id":"b9130dd8.46ecf","type":"debug","name":"","active":true,"console":"false","complete":"false","x":380,"y":374,"z":"d8bf240b.2740d8","wires":[]}]
```

References
==========

-   [Nest Thermostat](https://nest.com/)
   
- [Nest Developer Portal](https://developer.nest.com/)

-   [node-red-contrib-nest](https://github.com/hjespers/node-red-contrib-nest)

-   [Node-Red](http://nodered.org/)


