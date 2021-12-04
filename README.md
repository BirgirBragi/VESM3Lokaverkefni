# Leikurinn Pong á 64x64 rgb Matrix skjá

### Fyrsta Tilraun
---

#### Heimildir, Íhlutir o.fl.

íhlutir notaðir:

- Raspberry Pi Zero
- PowerBoost 1000C
- 64x64 rgb Matrix Skjár
- Adafruit rgb Matrix Bonnet
- DC power adapter
- SPDT Slide Switch
- 3 Lithium Batteries
- ESP32
- Joystick
- OLED

Tutorials sem stuðst var við

- https://learn.adafruit.com/matrix-led-sand
- https://howchoo.com/pi/raspberry-pi-led-matrix-panel

Upprunalega Hugmyndin:
 
Að nota joystick með Esp32 til þess að stýra Pong tölvuleik á rgb matrix skjá. Hægt væri síðan að birta high score sem gert væri yfir netið

---

#### Uppsetning

Fyrst var Adafruit rbg Matrix Bonnet sett ofan á Rasperry Pi Zero-inn og rafmagnið tengt frá Bonnetinu yfir í skjáinn með snúru. Einnig var red ribbon snúra tengd við Bonnetið og skjáinn

(mynd)

Síðan var pinni 4 lóðaður við pinna 18 á Bonnetinu

(mynd)

Síðan var SPDT Slide Switch lóðaður við ground á PowerBoost 1000C til þess að geta auðveldlega slökkt á rafmagninu.

(mynd af lóðuninni)

og snúrur tengdar á milli PowerBoost og Bonnetsins. Við það var DC power adapterinn notaður

(mynd)

Síðan var ekkert annað eftir heldur en að tengja batteríin í PowerBoostinn og við það fékk Bonnetinn, Raspberry Pi Zero-inn og matrix skjárinn rafmagn

(mynd)

---

#### Kóði

Að uppsetningunni lokinni var tími til þess að fá Matrix skjáinn til þess að virka með einföldu "Hello World!" dæmi. En til þess þurfti library fyrir raspberry pi

Heill fjagra klukkutíma tími í skólanum (þar sem kennari var ekki við) fór í það að prófa ýmis library og kóða til þess að fá skjáinn til þess að virka en alltaf fór eitthvað úrskeiðis með þessi blessuðu library. Við endurræstum raspberry pi, installuðum nýju OS, eyddum út öðrum libraryum sem gætu truflað, pössuðum vel upp á það að uppsetningin væri rétt en kjarninn á vandamálinu virtist ekki hafa neitt með okkur að gera. Vegna þess að þegar við installuðum [þessu](https://github.com/hzeller/rpi-rgb-led-matrix.git) library eftir hzeller af github fengum við error skilaboð sem gaf til kynna að það hreinlega vantaði sumar skrár í libraryinu. Þannig við kíktum örsnöggt í library möppuna og fundum allar möppur frá github libraryinu á sínum stað, en þær voru allar tómar. Gögn sem hefðu átt að installast með þegar við slógum inn "git clone https://github.com/hzeller/rpi-rgb-led-matrix.git" hreinlega voru ekki þarna.

Vegna ótal villumeldinga sem við fengum þrátt fyrir að hafa fylgt nákvæmlega leiðbeiningum og gert tilraunir með okkar eigin þekkingu bara til þess að fá skjáinn til þess að "virka". Þá ákváðum við að það væri best að skipta yfir í annan skjá til þess að geta skilað einhverju. Vegna þess að nú voru tveir fjagra klukkutíma tímar búnir og við höfðum einungis lokið við uppsetninguna. Næsta tilraun var því smá breyting á verkefninu, en í henni fólst að í staðinn fyrir rbg Matrix skjáinn þá var OLED notaður.

---

### Önnur Tilraun

