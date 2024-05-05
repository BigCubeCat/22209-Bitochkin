<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.10" tiledversion="1.10.2" name="bg" tilewidth="16" tileheight="16" tilecount="16" columns="4">
 <image source="../bg/bg.png" width="64" height="64"/>
 <tile id="1">
  <objectgroup draworder="index" id="2">
   <object id="1" x="1" y="1" width="14" height="14"/>
  </objectgroup>
 </tile>
 <tile id="2">
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="16" height="16"/>
  </objectgroup>
  <animation>
   <frame tileid="2" duration="200"/>
   <frame tileid="6" duration="200"/>
   <frame tileid="10" duration="200"/>
   <frame tileid="14" duration="200"/>
  </animation>
 </tile>
 <tile id="3" type="spawn">
  <objectgroup draworder="index" id="6">
   <object id="6" x="0" y="0" width="16" height="16">
    <ellipse/>
   </object>
  </objectgroup>
  <animation>
   <frame tileid="3" duration="200"/>
   <frame tileid="7" duration="200"/>
   <frame tileid="11" duration="200"/>
   <frame tileid="15" duration="200"/>
  </animation>
 </tile>
</tileset>
