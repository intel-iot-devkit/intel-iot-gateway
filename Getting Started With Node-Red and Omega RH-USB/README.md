# Getting Started With Node-RED and Omega* RH-USB #
<cr>

## Overview ##
Node-RED is a tool for wiring together hardware devices, APIs and online services in new and interesting ways. Node-RED provides a browser-based flow editor that makes it easy to wire together flows using the wide range nodes in the palette. Flows can be then deployed to the run-time in a single-click. The light-weight run-time is built on Node.js, taking full advantage of its event-driven, non-blocking model. This makes it ideal to run at the edge of the network. The Omega* RH-USB relative humidity/temperature sensor provides a standard USB output that directly feeds
relative humidity and temperature directly into the IoT gateway. The compact design is ideal for wall or duct mounting. Each unit is factory calibrated to provide excellent sensitivity, fast response, and stability. The unit features a simple installation with a direct USB
connection. The design features a 316 SS NEMA 4 (IP66) housing. A mounting kit is also available that allows for wall or duct mounting.

## Required Hardware ##
-   IoT Gateway that uses Intel® IoT Gateway Technology
-   Omega RH-USB Sensor

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Omega%20RH-USB/images/image1.png)

## Assumptions ##
-   Intel® IoT Gateway Technology version 3.1 or above
-   Node.js is installed on the IoT Gateway (installed by default)
-   Node-RED node node-red-node-serialport is installed on the IoT Gateway (installed by default)
-   Node-RED is installed on the IoT Gateway and is running (installed by default)

## Connecting the RH-USB Sensor ##
Plug the RH-USB sensor in to a USB port on your IoT Gateway. On the console of the IoT gateway, you should see a message saying what serial
device was created for the USB interface. It is likely /dev/ttyUSB0.
Please make a note of what device was created.

## Using Node-RED ##
The Node-RED browser interface can be reached via
<http://ipaddressofthegateway:1880>. When it first comes up it will look
something like this.

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Omega%20RH-USB/images/image2.png)

Let’s create a Node-RED flow to get the temperature reading from the RH-USB sensor.

Drag the following nodes from the left bar on to Sheet 1

-   Serial input
-   Serial output
-   function
-   debug

Now, configure the nodes:

-   Double click on the serial input node. Click on the pen icon to add a new serial port. In the Serial Port field, enter the device you noted above when you plugged the RH_USB sesnor in to the IoT Gateway. Likely /dev/ttyUSB0. Set the Baud Rate to 9600. Leave the other fields as default. For example:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Omega%20RH-USB/images/image3.png)

-   Click on OK/Update
-   Set the name to “RH-USB In” and click Ok.
-   Double click on the serial output node. Select the serial port you created in the steps above. Set the name to “RH-USB Out” and click on Ok.
-   Double click on the inject node. Set the Payload to string. Set the string to “F” (put the character F in the string field without quotes). Set the name to “Send F” and click on Ok.
-   Double click on the function node. Set the name to “Add Carriage return” and paste to following text in to the function body:

```

    msg.payload = msg.payload+"\r";
    return msg;
```

-   Click on Ok.
-   Now wire the RH-USB In node to the Debug node by clicking and dragging between the small box on the right of the RH-USB In to the small box on the left of the Debug node. It should look like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Omega%20RH-USB/images/image4.png)

-   Now wire the Send F inject node to the Add Carriage return function node and the Add Carriage return function node to the RH-USB Out serial node. It should look like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Omega%20RH-USB/images/image5.png)

-   Click on the Deploy button; top right.
-   Ensure the “debug” node is turned on. The box extending to the right of the debug should be solid/filled in green.
-   Switch the column on the right from the Info tab to the debug tab.
-   Click on the solid/filled in light blue box on the left side of the “Send F” inject node.
    -   You should see the current temperature i Fahrenheit returned in the debug tab. It should look like this:

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Omega%20RH-USB/images/image6.png)

-   In addition to sending an F to request temperature in Fahrenheit, you can also send the following commands. Try experimenting changing what you end in the Inject node to request different sensor readings.

    -   C - Temperature in Deg C.
    -   F - Temperature in Deg F.
    -   H - Relative Humidity
    -   ENQ - Model number and firmware version
    -   PA - Relative Humidity and Temperature in Deg F.

**Congratulations! You are successfully communicating via Serial to the Omega Relative Humidity USB Probe with Temperature Sensor.**

Example flow
============

Node-RED supports exporting and importing of flows (into source json).
Here is an export of the above two flows we created. If you import this,
the same nodes and configuration we created manually will automatically
appear on the selected Sheet. Import and Export can be found in the
Node-RED menu by clicking on the 3 horizontal lines to the right of the
Deploy button.

    [{"id":"f4321530.0bcde8","type":"serial-port","z":"9d03f5b9.62fc08","serialport":"/dev/ttyUSB0","serialbaud":"9600","databits":"8","parity":"none","stopbits":"1","newline":"\\n","bin":"false","out":"char","addchar":false},{"id":"7f80e374.807f1c","type":"serial in","z":"9d03f5b9.62fc08","name":"Sensor Input","serial":"f4321530.0bcde8","x":253,"y":229,"wires":[["bc8f30ff.4370d"]]},{"id":"bc8f30ff.4370d","type":"debug","z":"9d03f5b9.62fc08","name":"","active":true,"console":"false","complete":"true","x":489,"y":246,"wires":[]},{"id":"62a0948b.9d5f6c","type":"serial out","z":"9d03f5b9.62fc08","name":"Sensor Output","serial":"f4321530.0bcde8","x":613,"y":317,"wires":[]},{"id":"54a038a6.ab5fc8","type":"inject","z":"9d03f5b9.62fc08","name":"Send F","topic":"","payload":"F","payloadType":"string","repeat":"","crontab":"","once":false,"x":192,"y":324,"wires":[["e664133d.199bf"]]},{"id":"e664133d.199bf","type":"function","z":"9d03f5b9.62fc08","name":"Add Carriage Return","func":"msg.payload = msg.payload+\"\\r\"; \nreturn msg;","outputs":1,"noerr":0,"x":387,"y":325,"wires":[["62a0948b.9d5f6c"]]}]


## References ##
-   [Omega RH-USB](http://www.omega.com/pptst/RH-USB.html)
-   [Omega RH-USB Command Reference](ftp://ftp.omega.com/public/DASGroup/products/RH-USB/RH_USB%20Command%20Reference.pdf)
-   [Node-red-node-serialport](http://flows.nodered.org/node/node-red-node-serialport)
-   [Node-RED](http://nodered.org/)

*indicates that third-party names might be the property of others.

