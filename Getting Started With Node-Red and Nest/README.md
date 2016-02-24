# Getting Started With Node-RED and Nest* #
<cr>

## Overview ##
Node-RED is a tool for wiring together hardware devices, APIs and online services in new and interesting ways. Node-RED provides a browser-based flow editor that makes it easy to wire together flows using the wide
range nodes in the palette. Flows can be then deployed to the run-time in a single-click. The light-weight run-time is built on Node.js, taking full advantage of its event-driven, non-blocking model. This makes it ideal to run at the edge of the network. Turn it up, turn it down. The Nest* Learning Thermostat remembers what temperatures you like, creates a custom schedule for your home, and turns itself down when you’re away. Once it’s learned your schedule, Nest can save 20% on your heating and cooling bills. And if you want remote control, just use your smart phone, tablet or computer. Nest System Match optimizes controls for your heating and cooling system, while the Nest Leaf guides you to energy-efficient temperatures. With Energy History and Energy Report, you can see how much energy you’ve used and get tips to help you save more.

## Required Hardware ##
- IoT Gateway that uses Intel® IoT Gateway Technology
- Nest Thermostat and optionally Nest Protect

![](image1.png)
![](image1.5.png)

## Assumptions ##
- Intel® IoT Gateway Technology version 3.1 or above
- Node.js is installed on the IoT Gateway (installed by default)
- Node-RED node node-red-contrib-nest is installed on the IoT Gateway
	- You can install this package by clicking on Packages and then Add Packages from the Intel® IoT Gateway Developer Hub
- Node-RED is installed on the IoT Gateway and is running (installed by default)
- Nest products (Thermostat(s) and or Protect(s) are installed, functioning, and are connected to a Nest cloud account

## Nest Developer Account Setup ##
You will need a Nest Developer Program account account to query your the Nest cloud for your Nest data.  

Create a [Nest developer portal](https://developer.nest.com/) account and log in.

Click on "Create a Cloud Product"

- Give your product a unique name
- Enter a description
- Set the Categories to Home Automation and Building for example
- Set the users to Individual
- The Support URL is a required field but not needed for this example.  Set it to something appropriate for you
- Leave the Redirect URI blank to enable the PIN CODE authentication process
- Check the boxes in the Permissions section for Thermostat, Away,  and Smoke_CO Alarm (if you have a Nest Protect).
	- Within each area, enter a brief description of the permission.  This text shows up when you authenticate an application to the service.  This doesn't matter for the tutorial.
	- Optionally, within each area, change to read/write if you want to be able to change settings from within Node-RED (not part of this tutorial)
- Click on Create Product
- Your new Product will now be listed.  Click on it to see the details
- Keep the web page open as you'll need the Product ID, Product Secret, Authorization URL, and Access Token URL information later.

## Using Node-RED ##
The Node-RED browser interface can be reached via
<http://ipaddressofthegateway:1880>. When it first comes up it will look
something like this.

![](image2.png)

Let’s create a Node-RED flow to get the readings from the Nest product(s).

Drag the following nodes from the left bar on to Sheet 1

- inject
- nest request
- function
- debug
- mqtt

Now, configure the nodes:

**nest request node**

- Double click on the nest request node.
- Click on the pen icon to add a new account.
- Cut and paste the Product ID from the Nest Developer web page you left open above in to the Client ID field
- Cut and paste the Product Secret from the Nest Developer web page to the Client Secret field
- Click on the Authorize button.  A web page will launch and show you the Nest Product information you created in the Nest Developer web site.  Click on Accept.
- Type the Pincode displayed in to the Pincode filed back in Node-RED node.
- Click on the Generate Token button.  A token will be crated and the field will be automatically filled in.  
- Click on Add
- Ensure the Type is set to Thermostat(s)
- Set the Name field to "Nest Temp"
- Click on Ok

**function node**

- Double click on the function node
- Set the name to temp only
- Copy and Paste this code in to the function body.  This function will get just the temperature value from the first thermostat that comes back in the set of data retrieved from the Nest cloud.
	- Note: If you have a 2nd Nest, you can change the output value in the function to 2.  The temperature of the 1st thermostat reported by the Nest cloud will go to output 1 and the temperature of the 2nd thermostat will go to output 2

```

	//var obj = JSON.parse(msg.payload);
	var obj = msg.payload;
	var messages = [];

	// .ambient_temperature_f
	for(var key in obj)
	{
	    if (obj.hasOwnProperty(key))
	    {
	        messages.push({payload: obj[key].ambient_temperature_f});
	    }
	}

	return messages;
```

- Now wire the inject node to the Nest Temp node by clicking and dragging between the small box on the right of the inject In node to the small box on the left of the Nest Temp node. 
- Repeat the process for to wire the Nest Temp node to the temp only function node and again to wire the temp only node to the debug node.
	- Note: If you have a 2nd thermostat, you can add a 2nd debug node and wire it to the 2nd output on the function node)

- It should look like this:

![](image3.png)

- Click on the Deploy button, top right, and Confirm deploy.
- Ensure the “debug” node is turned on. The box extending to the right of the node should be solid/filled in green.
- Switch the column on the right from the Info tab to the debug tab.
- Click on the blue box to the left of the inject node.
- The current temperature should appear as part of the payload message  should appear as part of the payload message in the debug tab.

**Congratulations! You are successfully communicating via IP/Cloud to the Nest Thermostat.**


Now let's get visualize the Nest thermostat data to the Intel IoT Developer Hub.

- Add a chart node and a mqtt node to the sheet
- Double click on the chart node and set the values as follows
	- Title = Nest Temperature
	- Type = Gauge
	- Priority = 3 (placement of chart group across Dev Hub)
	- Units = °F
	- Range = 60 to 80
	- Target = (blank)
	- Points = 50
	- Source = Nest Cloud
	- TTL = 10
	- Source Priority = 1 (placement of chart within chart group)
	- Click on Ok
- Double click on the mqtt node and set the values as follows
	- Server = localhost:1833 (should already be selectable in the drop down)
	- Topic = /sensors
	- Click on Ok

Now wire the output of the temp only function to the Nest Temperature chart node and the Net Temperate Chart node to the /sensors mqtt node.
It should look like this.

![](image4.png)

- Click on the Deploy button, top right.
- Now view the Intel® IoT Gateway Developer Hub via a web browser.  You should see a new sensor and graph called Nest Temperature.

**Congratulations! You are successfully displaying sensor data from your Nest on the IoT Gateway.**

## Example flow ##
Node-RED supports exporting and importing of flows (into source json).  Here is an export of the above two flows we created. If you import this, the same nodes and configuration we created manually will automatically
appear on the selected Sheet. Import and Export can be found in the Node-RED menu by clicking on the 3 horizontal lines to the right of the Deploy button.

    [{"id":"baabe7c7.455418","type":"mqtt-broker","z":"","broker":"localhost","port":"1883","clientid":"","usetls":false,"verifyservercert":true,"compatmode":true,"keepalive":"15","cleansession":true,"willTopic":"","willQos":"0","willRetain":"false","willPayload":"","birthTopic":"","birthQos":"0","birthRetain":"false","birthPayload":""},{"id":"8b99208b.7466e","type":"nest request","z":"69a52aa4.965ad4","account":"","devicetype":"thermostats","deviceid":"","streaming":"false","name":"Nest Temp","x":259,"y":538,"wires":[["a6bbb09c.59445"]]},{"id":"615eaec.f9ea15","type":"debug","z":"69a52aa4.965ad4","name":"","active":true,"console":"false","complete":"payload","x":615,"y":555,"wires":[]},{"id":"816e2d27.7e91d","type":"inject","z":"69a52aa4.965ad4","name":"","topic":"","payload":"","payloadType":"date","repeat":"5","crontab":"","once":true,"x":118,"y":495,"wires":[["8b99208b.7466e"]]},{"id":"a6bbb09c.59445","type":"function","z":"69a52aa4.965ad4","name":"temp only","func":"//var obj = JSON.parse(msg.payload);\nvar obj = msg.payload;\nvar messages = [];\n\n// .ambient_temperature_f\nfor(var key in obj)\n{\nif (obj.hasOwnProperty(key))\n{\nmessages.push({payload: obj[key].ambient_temperature_f});\n}\n}\n\nreturn messages;","outputs":"2","noerr":0,"x":422,"y":575,"wires":[["615eaec.f9ea15","bcd1e393.432e2"],[]]},{"id":"7768cbc.f889734","type":"mqtt out","z":"69a52aa4.965ad4","name":"","topic":"/sensors","qos":"","retain":"","broker":"baabe7c7.455418","x":803,"y":562,"wires":[]},{"id":"bcd1e393.432e2","type":"chart tag","z":"69a52aa4.965ad4","title":"Nest Temperature","chartType":"gauge","dataSource":"Nest Cloud","units":"°F","min":"60","max":"80","targetLow":"68","targetHigh":"72","priority":"2","sourcePriority":"1","ttl":"5","points":50,"x":621,"y":500,"wires":[["7768cbc.f889734"]]}]

## References ##
- [Nest Thermostat](https://nest.com/)
- [Nest Developer Portal](https://developer.nest.com/)
- [node-red-contrib-nest](https://github.com/hjespers/node-red-contrib-nest)
- [Node-RED](http://nodered.org/)

*indicates that third-party names might be the property of others.