# Getting Started With Node-Red and Z-Wave #
<cr>

## Overview ##
Node-RED is a tool for wiring together hardware devices, APIs and online services in new and interesting ways. Node-RED provides a browser-based flow editor that makes it easy to wire together flows using the wide range nodes in the palette. Flows can be then deployed to the runtime in a single-click. The light-weight runtime is built on Node.js, taking full advantage of its event-driven, non-blocking model. This makes it ideal to run at the edge of the network. Z-Wave is a wireless technology that makes regular household products, like lights, door locks and
thermostats "smart". Z-Wave products "talk" to each other wirelessly and securely and can be accessed and controlled on your phone, tablet or pc.  By using a Z-Wave gateway you can connect to the things inside your house whether you're at home or while you're away. Currently there are
nearly 1000 different Z-Wave products that all work together.

## Required Hardware ##
-   Intel Internet of Things Gateway
-   Z-Wave controller interface (USB)
    -   *In this example, we used an Aeon Labs DSA02203-ZWUS Z-Wave Z-Stick Series 2*

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Z-Wave/images/image1.jpeg)

-   At least one Z-Wave device
    -   A simple plug in lamp module and a desk lamp is a good place to start for initial testing. *In this example, we used a GE Plug-in Smart Switch model 12719.*

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Z-Wave/images/image2.jpeg)

## Assumptions ##
-   Intel Internet of Things Gateway is running version 3.1 or above
-   Node.js is installed on the Intel IoT Gateway (installed by default)
-   Z-Wave controller is plugged in to a USB port on the Intel IoT Gateway
-	Z-Wave package is installed from the Intel IoT Gateway Developer Hub Interface.  You can install these packages by clicking on Packages and then Add Packages from the Intel IoT Gateway Developer Hub interface.  The Z-Wave package includes:
	-   OpenZWave library and headers
	-   Node.js add-on node-openzwave-shared
	-   Node-red node node-red-contrib-openzwave 
-   Node-Red is installed on the Intel IoT Gateway and is running (installed by default)

## Setting up a Z-Wave Network ##
Before the Z-Wave controller can talk to a Z-Wave device, the device needs to be added or provisioned to the controller. This can be done via software or in the case of the Aeon Labs Z-Stick, via the physical
button on the USB interface.

1.  Stop Node-Red if it is running

>systemctl stop node-red-experience

2.  Unplug the Z-Wave Aeon Labs Z-Stick from the Intel IoT Gateway
3.  Plug the Z-Wave Smart Switch in to an outlet or power strip
4.  Press the button on the Aeon Labs Z-Stick. The light should start to flash slowly.
5.  Within 10 seconds, press the button on the Z-Wave Smart Switch. You should see the light on the Aeon Labs Z-Stick blink and then return to flashing slowly.
	-  Repeat on other Z-Wave devices if you are adding more than one
6.  Press the button on the Aeon Labs Z-Stick. The light should go out.
7.  Plug the Aeon Labs Z-Stick back in the USB port on the Intel IoT Gateway
    -  Node the device Linux assigns on the console output.  Likely /dev/ttyUSB0.
8.  Start Node-Red

>systemctl start node-red-experience

## Using Node-Red ##
The Node-Red browser interface can be reached via
<http://ipaddressofthegateway:1880>. When it first comes up it will look
something like this.

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Z-Wave/images/image3.png)

Drag the following nodes from the left bar on to Sheet 1

-   inject (2 instances)
-   zwave out
-   zwave in
-   debug

First, we need to get the Z-Wave Node ID from the Smart Switch you added in Setting up the Z-Wave Network section. Here’s how we can get that info.

-   Double click on the zwave in node and name it “z-wave in”.
-   Then click on the Controller filed and select add new controller.  Enter the device location of the port the USB Z-Wave interface is plugged in to. Likely /dev/ttyUSB0. Click on Add. Click on Ok.
-   Double click on the debug node, green and likely called msg.payload.  Set its name to “z-wave in debug” and click on ok
-   Now wire the “z-wave in” node to the “z-wave in debug” node by clicking and dragging between the small box on the right of the “z-wave in” node to the small box on the left of the “z-wave in debug node”.
-   It should look like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Z-Wave/images/image4.png)

-   Click on the Deploy button, top right, and Confirm deploy. It’s ok some of the nodes are not setup yet. We’ll get to those next.
-   Ensure the “z-wave in debug” node is turned on. The box extending to the right of the node should be solid/filled in green.
-   Switch the column on the right from the Info tab to the debug tab.
-   Press the button on the Z-Wave Smart Switch. The lamp should toggle on/off. A debug message like this should appear each time you toggle the Smart Switch.

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Z-Wave/images/image5.png)

-   Note the numeric value listed after “nodeid”. In this case, it’s 4.

Ok, now that we know the node id, let’s setup a flow to control the Z-Wave Smart Switch

-   Double click on one of the inject nodes. Set the fields as follows:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Z-Wave/images/image6.png)

-	Replace the nodeid numeric value with the value of your z-wave switch as you noted above*
-   Click on Ok
-   Double click on the other inject node. Set the fields as follows:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Z-Wave/images/image7.png)

-	Replace the nodeid numeric value with the value of your z-wave switch as you noted above*
-   Click on Ok
-   Double click on the zwave out node and name it “z-wave out”.
-   Then click on the Controller filed and select add new controller.  Enter the device location of the port the USB Z-Wave interface is plugged in to. Likely /dev/ttyUSB0. Click on Add. Click on Ok.
-   Now wire the “Light On” and Light Off nodes to the “z-wave out” node by clicking and dragging between the small box on the right of each node to the small box on the left of the “z-wave out” node.
-   It should look like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Z-Wave/images/image8.png)

Your two flows together should look like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Z-Wave/images/image9.png)

-   Click on the Deploy button, top right, and Confirm deploy
-   Click on the solid/filled in light blue box on the left side of the “Light On” inject node.
    -   The Z-Wave Smart Switch and lamp should turn on
-   Click on the solid/filled in light blue box on the left side of the “Light Off” inject node.
    -   The Z-Wave Smart Switch and lamp should turn off

**Congratulations! You are successfully communicating via Z-Wave to Z-Wave devices; controlling and sensing.**

## Example flow ##
Node-Red supports exporting and importing of flows (into source json). Here is an export of the above two flows we created. If you import this, the same nodes and configuration we created manually will automatically
appear on the selected Sheet. Import and Export can be found in the Node-Red menu by clicking on the 3 horizontal lines to the right of the
Deploy button.

    [{"id":"9d41a5d9.62be58","type":"zwave-controller","port":"/dev/ttyUSB0","driverattempts":"3","pollinterval":"500"},{"id":"49f6bc58.b60944","type":"zwave-in","name":"z-wave in","controller":"9d41a5d9.62be58","x":161,"y":205,"z":"71d5b1a3.8e2a5","wires":[["4d8a73fb.b2758c"]]},{"id":"2b05244c.d4fadc","type":"inject","name":"Light on","topic":"'switchOn'","payload":"{\"nodeid\":4}","payloadType":"string","repeat":"","crontab":"","once":false,"x":168,"y":64,"z":"71d5b1a3.8e2a5","wires":[["4067c55d.bf983c"]]},{"id":"ee7f0d6b.1180f","type":"inject","name":"Light Off","topic":"'switchOff'","payload":"{\"nodeid\":4}","payloadType":"string","repeat":"","crontab":"","once":false,"x":171,"y":126,"z":"71d5b1a3.8e2a5","wires":[["4067c55d.bf983c"]]},{"id":"4067c55d.bf983c","type":"zwave-out","name":"z-wave out","controller":"9d41a5d9.62be58","x":446,"y":91,"z":"71d5b1a3.8e2a5","wires":[]},{"id":"4d8a73fb.b2758c","type":"debug","name":"z-wave in debug","active":true,"console":"false","complete":"payload","x":396,"y":204,"z":"71d5b1a3.8e2a5","wires":[]}]

## Supported (by OpenZwave) Z-Wave Devices/Sensors ##
-   [Z-Wave Products](http://products.z-wavealliance.org/)

## References ##
-   [Node-Red](http://nodered.org/)
-   [node-red-contrib-openzwave](http://flows.nodered.org/node/node-red-contrib-openzwave)
-   [OpenZWave](http://www.openzwave.com/)
-   [node-openzwave-shared](https://github.com/OpenZWave/node-openzwave-shared)
-   [Z-Wave](http://www.z-wave.com/home)
-   [Z-Wave Alliance](http://z-wavealliance.org/)
-   [Official Z-Wave Stack (from Sigma Designs)](http://z-wave.sigmadesigns.com/)

## Note ##
The Z-Wave library used in this example is the community supported OpenZWave stack. This is a Reverse Engineered implementation of the official Z-Wave stack from Sigma Designs. Details on the official stack can be found [here](http://z-wave.sigmadesigns.com/).  The official stack is recommenced for any production deployments.
