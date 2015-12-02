Overview
========

Node-RED is a tool for wiring together hardware devices, APIs and online
services in new and interesting ways. Node-RED provides a browser-based
flow editor that makes it easy to wire together flows using the wide
range nodes in the palette. Flows can be then deployed to the runtime in
a single-click. The light-weight runtime is built on Node.js, taking
full advantage of its event-driven, non-blocking model. This makes it
ideal to run at the edge of the network. Z-Wave is a wireless technology
that makes regular household products, like lights, door locks and
thermostats "smart". Z-Wave products "talk" to each other wirelessly and
securely and can be accessed and controlled on your phone, tablet or pc.
By using a Z-Wave gateway you can connect to the things inside your
house whether you're at home or while you're away. Currently there are
nearly 1000 different Z-Wave products that all work together.

Required Hardware
=================

-   Intel Internet of Things Gateway

-   Z-Wave controller interface (USB)

    -   *In this example, we used an Aeon Labs DSA02203-ZWUS Z-Wave
        Z-Stick Series 2*

> ![](media/image1.jpeg)

-   At least one Z-Wave device

    -   A simple plug in lamp module and a desk lamp is a good place to
        start for initial testing. *In this example, we used a GE
        Plug-in Smart Switch model 12719.*

> ![](media/image2.jpeg)

Assumptions
===========

-   Intel Internet of Things Gateway is running the WindRiver
    Intelligent Device Platform (IDP) version 3.0 or above

-   Z-Wave controller is plugged in to a USB port on the Intel IoT
    Gateway

-   Node.js is installed on the Intel IoT Gateway

-   OpenZWave library and headers are installed on the Intel IoT Gateway

-   Node.js add-on node-openzwave-shared is installed on the Intel IoT
    Gateway

-   Node-red node node-red-contrib-openzwave is installed on the Intel
    IoT Gateway

-   Node-Red is installed on the Intel IoT Gateway and is running

Setting up a Z-Wave Network
===========================

Before the Z-Wave controller can talk to a Z-Wave device, the device
needs to be added or provisioned to the controller. This can be done via
software or in the case of the Aeon Labs Z-Stick, via the physical
button on the USB interface.

1.  Stop Node-Red if it is running

2.  Unplug the Z-Wave Aeon Labs Z-Stick from the Intel IoT Gateway

3.  Plug the Z-Wave Smart Switch in to an outlet or power strip

4.  Press the button on the Aeon Labs Z-Stick. The light should start to
    flash slowly.

5.  Within 10 seconds, press the button on the Z-Wave Smart Switch. You
    should see the light on the Aeon Labs Z-Stick blink and then return
    to flashing slowly.

    a.  Repeat on other Z-Wave devices if you are adding more than one

6.  Press the button on the Aeon Labs Z-Stick. The light should go out.

7.  Plug the Aeon Labs Z-Stick back in the USB port on the Intel IoT
    Gateway

    a.  Node the device Linux assigns on the console output.
        Likely /dev/ttyUSB0.

8.  Start Node-Red

Using Node-Red
==============

The Node-Red browser interface can be reached via
<http://ipaddressofthegateway:1880>. When it first comes up it will look
something like this.

![](media/image3.png)

Drag the following nodes from the left bar on to Sheet 1

-   inject (2 instances)

-   zwave out

-   zwave in

-   debug

1^st^ we need to get the Z-Wave Node ID from the Smart Switch you added
in Setting up the Z-Wave Network section. Here’s how we can get that
info.

-   Double click on the zwave in node and name it “z-wave in”.

-   Then click on the Controller filed and select add new controller.
    Enter the device location of the port the USB Z-Wave interface is
    plugged in to. Likely /dev/ttyUSB0. Click on Add. Click on Ok.

-   Double click on the debug node, green and likely called msg.payload.
    Set its name to “z-wave in debug” and click on ok

-   Now wire the “z-wave in” node to the “z-wave in debug” node by
    clicking and dragging between the small box on the right of the
    “z-wave in” node to the small box on the left of the “z-wave in
    debug node”.

-   It should look like this:

> ![](media/image4.png)

-   Click on the Deploy button, top right, and Confirm deploy. It’s ok
    some of the nodes are not setup yet. We’ll get to those next.

-   Ensure the “z-wave in debug” node is turned on. The box extending to
    the right of the node should be solid/filled in green.

-   Switch the column on the right from the Info tab to the debug tab.

-   Press the button on the Z-Wave Smart Switch. The lamp should
    toggle on/off. A debug message like this should appear each time you
    toggle the Smart Switch.

> ![](media/image5.png)

-   Note the numeric value listed after “nodeid”. In this case, it’s 4.

Ok, now that we know the node id, let’s setup a flow to control the
Z-Wave Smart Switch

-   Double click on one of the inject nodes. Set the fields as follows:

> ![](media/image6.png)\
> *Replace the nodeid numeric value with the value of your z-wave switch
> as you noted above*

-   Click on Ok

-   Double click on the other inject node. Set the fields as follows:

> ![](media/image7.png)\
> *Replace the nodeid numeric value with the value of your z-wave switch
> as you noted above*

-   Click on Ok

-   Double click on the zwave out node and name it “z-wave out”.

-   Then click on the Controller filed and select add new controller.
    Enter the device location of the port the USB Z-Wave interface is
    plugged in to. Likely /dev/ttyUSB0. Click on Add. Click on Ok.

-   Now wire the “Light On” and Light Off nodes to the “z-wave out” node
    by clicking and dragging between the small box on the right of each
    node to the small box on the left of the “z-wave out” node.

-   It should look like this:\
    ![](media/image8.png)

-   Click on the Deploy button, top right, and Confirm deploy

-   Click on the solid/filled in light blue box on the left side of the
    “Light On” inject node.

    -   The Z-Wave Smart Switch and lamp should turn on

-   Click on the solid/filled in light blue box on the left side of the
    “Light Off” inject node.

    -   The Z-Wave Smart Switch and lamp should turn off

        Congratulations! You are successfully communicating via Z-Wave
        to Z-Wave devices; controlling and sensing.

        Your two flows together should look like this:

        ![](media/image9.png)

Example flow
============

Node-Red supports exporting and importing of flows (into source json).
Here is an export of the above two flows we created. If you import this,
the same nodes and configuration we created manually will automatically
appear on the selected Sheet. Import and Export can be found in the
Node-Red menu by clicking on the 3 horizontal lines to the right of the
Deploy button.

Supported Sensors
=================

-   [Z-Wave Products](http://products.z-wavealliance.org/)

References
==========

-   [Node-Red](http://nodered.org/)

-   [node-red-contrib-openzwave](http://flows.nodered.org/node/node-red-contrib-openzwave)

-   [OpenZWave](http://www.openzwave.com/)

-   [node-openzwave-shared](https://github.com/OpenZWave/node-openzwave-shared)

-   [Z-Wave](http://www.z-wave.com/home)

-   [Z-Wave Alliance](http://z-wavealliance.org/)

-   [Official Z-Wave Stack (from
    Sigma Designs)](http://z-wave.sigmadesigns.com/)

Note
====

The Z-Wave library used in this example is the community supported
OpenZWave stack. This is a Reverse Engineered implementation of the
official Z-Wave stack from Sigma Designs. Details on the official can be
found [here](http://z-wave.sigmadesigns.com/).
