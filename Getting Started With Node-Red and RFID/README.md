# Getting Started With Node-Red and RFID #
<cr>

## Overview ##
Node-RED is a tool for wiring together hardware devices, APIs and online services in new and interesting ways. Node-RED provides a browser-based flow editor that makes it easy to wire together flows using the wide
range nodes in the palette. Flows can be then deployed to the runtime in a single-click. The light-weight runtime is built on Node.js, taking full advantage of its event-driven, non-blocking model. This makes it ideal to run at the edge of the network. The SparkFun RFID Starter Kit,
an all-in-one kit that offer everything you need to create a RFID project. The kit includes a USB RFID Reader, ID-12LA RFID module, and two 125kHz RFID cards.

## Required Hardware ##
-   Intel Internet of Things Gateway
-   SparkFun RFID Starter Kit
-   USB Mini-B Cable

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20RFID/images/image1.jpeg)

## Assumptions ##
-   Intel Internet of Things Gateway is running version 3.1 or above
-   Node.js is installed on the Intel IoT Gateway (installed by default)
-   Node-red node node-red-node-serialport is installed on the Intel IoT Gateway (installed by default)
-   Node-Red is installed on the Intel IoT Gateway and is running (installed by default)

## Connecting the RFID Reader ##
Plug the RFID reader in to the board. Plug the small end of the USB cable in to the board. Plug the other end of the USB cable in to a USB port on your Intel IoT Gateway. On the console of the gateway, you should see a message saying what serial device was created for the USB
interface. It is likely /dev/ttyUSB0. Please make a note of what device was created.

## Using Node-Red ##
The Node-Red browser interface can be reached via
<http://ipaddressofthegateway:1880>. When it first comes up it will look
something like this.

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20RFID/images/image2.png)

Let’s create a node-red flow to get the badge readings from the RFID reader.

Drag the following nodes from the left bar on to Sheet 1

-   Serial input
-   debug

Now, configure the nodes:

-   Double click on the serial node. Click on the pen icon to add a new serial port. In the Serial Port field, enter the device you noted above when you plugged the RFID reader in to the Intel IoT Gateway. Likely /dev/ttyUSB0. Set the Baud Rate to 9600. Leave the other fields as default. For example:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20RFID/images/image3.png)

-   Click on OK/Update
-   Set the name to “RFID In”. For example:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20RFID/images/image4.png)

-   Click OK
-   Now wire the RFID In node to the Debug node by clicking and dragging between the small box on the right of the RFID In node to the small box on the left of the Debug node. It should look like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20RFID/images/image5.png)

-   Click on the Deploy button, top right, and Confirm deploy.
-   Ensure the “debug” node is turned on. The box extending to the right of the node should be solid/filled in green.
-   Switch the column on the right from the Info tab to the debug tab.
-   Scan one of your badges.
    -   The badge ID should appear as part of the payload message in the debug tab.
-   Scan your other badge.
    -   The badge ID should appear as part of the payload message in the debug tab.

**Congratulations! You are successfully communicating via Serial to a RFID reader device.**

## Example flow ##
Node-Red supports exporting and importing of flows (into source json).
Here is an export of the above two flows we created. If you import this,
the same nodes and configuration we created manually will automatically
appear on the selected Sheet. Import and Export can be found in the
Node-Red menu by clicking on the 3 horizontal lines to the right of the
Deploy button.

    [{"id":"7bc6f0f3.84391","type":"serial-port","serialport":"/dev/ttyUSB0","serialbaud":"9600","databits":"8","parity":"none","stopbits":"1","newline":"\\n","bin":"false","out":"char","addchar":false},{"id":"b8d1dd75.472e2","type":"serial in","name":"RFID In","serial":"7bc6f0f3.84391","x":154,"y":376,"z":"d8bf240b.2740d8","wires":[["b9130dd8.46ecf"]]},{"id":"b9130dd8.46ecf","type":"debug","name":"","active":true,"console":"false","complete":"false","x":380,"y":374,"z":"d8bf240b.2740d8","wires":[]}]

## References ##
-   [SparkFun RFID Starter Kit](https://www.sparkfun.com/products/13198)
-   [Node-red-node-serialport](http://flows.nodered.org/node/node-red-node-serialport)
-   [Node-Red](http://nodered.org/)


