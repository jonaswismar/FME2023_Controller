#include <Arduino.h>

#include "filesystem\functions.h"

#include "variables.h"

String getAlarmPLZText(unsigned int currentPLZ)
{
     String currentAlarmText = "";
     switch (currentPLZ)
     {
     case 1:
     {
          currentAlarmText = F("35390");
          break;
     }
     case 2:
     {
          currentAlarmText = F("35392");
          break;
     }
     case 3:
     {
          currentAlarmText = F("35394");
          break;
     }
     case 4:
     {
          currentAlarmText = F("35396");
          break;
     }
     case 5:
     {
          currentAlarmText = F("35398");
          break;
     }
     }
     return currentAlarmText;
}

String getAlarmCityText(unsigned int currentCity)
{
     String currentAlarmText = "";
     switch (currentCity)
     {
     case 1:
     {
          currentAlarmText = F("Allendorf");
          break;
     }
     case 2:
     {
          currentAlarmText = F("Gießen");
          break;
     }
     case 3:
     {
          currentAlarmText = F("Kleinlinden");
          break;
     }
     case 4:
     {
          currentAlarmText = F("Lützellinden");
          break;
     }
     case 5:
     {
          currentAlarmText = F("Rödgen");
          break;
     }
     case 6:
     {
          currentAlarmText = F("Wieseck");
          break;
     }
     }
     return currentAlarmText;
}

String getAlarmStreetText(unsigned int currentStreet)
{
     String currentAlarmText = "";
     switch (currentStreet)
     {
     case 800:
     {
          currentAlarmText = F("Außerhalb");
          break;
     }
     case 801:
     {
          currentAlarmText = F("Koordinaten");
          break;
     }
          // Allendorf
     case 21:
     {
          currentAlarmText = F("Altes Gericht");
          break;
     }
     case 25:
     {
          currentAlarmText = F("Am Alten Steinbruch");
          break;
     }
     case 33:
     {
          currentAlarmText = F("Am Gallichten");
          break;
     }
     case 38:
     {
          currentAlarmText = F("Am Kasimir");
          break;
     }
     case 41:
     {
          currentAlarmText = F("Am Sportplatz");
          break;
     }
     case 52:
     {
          currentAlarmText = F("Am Weinberg");
          break;
     }
     case 53:
     {
          currentAlarmText = F("Am Zehntfrei");
          break;
     }
     case 77:
     {
          currentAlarmText = F("Aubach");
          break;
     }
     case 100:
     {
          currentAlarmText = F("Bergstrasse");
          break;
     }
     case 178:
     {
          currentAlarmText = F("Ehrsamer Weg");
          break;
     }
     case 218:
     {
          currentAlarmText = F("Friedhofstrasse");
          break;
     }
     case 243:
     {
          currentAlarmText = F("Gerichtsspitz");
          break;
     }
     case 309:
     {
          currentAlarmText = F("Hintergasse");
          break;
     }
     case 311:
     {
          currentAlarmText = F("Hochstrasse");
          break;
     }
     case 324:
     {
          currentAlarmText = F("Hoppensteinstrasse");
          break;
     }
     case 332:
     {
          currentAlarmText = F("Hüttenbergstrasse");
          break;
     }
     case 339:
     {
          currentAlarmText = F("Im Kleefeld");
          break;
     }
     case 345:
     {
          currentAlarmText = F("In der Lache");
          break;
     }
     case 366:
     {
          currentAlarmText = F("Kahlweg");
          break;
     }
     case 395:
     {
          currentAlarmText = F("Kleebachstrasse");
          break;
     }
     case 398:
     {
          currentAlarmText = F("Kleinlindener Strasse");
          break;
     }
     case 406:
     {
          currentAlarmText = F("Krautgarten");
          break;
     }
     case 412:
     {
          currentAlarmText = F("Lahnparkstrasse");
          break;
     }
     case 504:
     {
          currentAlarmText = F("Obergasse");
          break;
     }
     case 585:
     {
          currentAlarmText = F("Schneiderhenn");
          break;
     }
     case 639:
     {
          currentAlarmText = F("Teilgärtenweg");
          break;
     }
     case 649:
     {
          currentAlarmText = F("Triebstrasse");
          break;
     }
     case 656:
     {
          currentAlarmText = F("Über der Seife");
          break;
     }
     case 662:
     {
          currentAlarmText = F("Untergasse");
          break;
     }
          // Gießen
     case 1:
     {
          currentAlarmText = F("Adalbert-Stifter-Strasse");
          break;
     }
     case 2:
     {
          currentAlarmText = F("Adam-Scheurer-Strasse");
          break;
     }
     case 3:
     {
          currentAlarmText = F("Adolph-Kolping-Strasse");
          break;
     }
     case 4:
     {
          currentAlarmText = F("Ahornweg");
          break;
     }
     case 6:
     {
          currentAlarmText = F("Albert-Schweitzer-Strasse");
          break;
     }
     case 7:
     {
          currentAlarmText = F("Alfred-Bock-Strasse");
          break;
     }
     case 8:
     {
          currentAlarmText = F("Alicenstrasse");
          break;
     }
     case 11:
     {
          currentAlarmText = F("Altarasstrasse");
          break;
     }
     case 12:
     {
          currentAlarmText = F("Alte Gerberei");
          break;
     }
     case 14:
     {
          currentAlarmText = F("Altenbergweg");
          break;
     }
     case 17:
     {
          currentAlarmText = F("Altenfeldsweg");
          break;
     }
     case 18:
     {
          currentAlarmText = F("Alter Krofdorfer Weg");
          break;
     }
     case 19:
     {
          currentAlarmText = F("Alter Steinbacher Weg");
          break;
     }
     case 20:
     {
          currentAlarmText = F("Alter Wetzlarer Weg");
          break;
     }
     case 22:
     {
          currentAlarmText = F("Am Alten Flughafen");
          break;
     }
     case 23:
     {
          currentAlarmText = F("Am Alten Friedhof");
          break;
     }
     case 24:
     {
          currentAlarmText = F("Am Alten Gaswerk");
          break;
     }
     case 28:
     {
          currentAlarmText = F("Am Bergwerkswald");
          break;
     }
     case 29:
     {
          currentAlarmText = F("Am Brennofen");
          break;
     }
     case 34:
     {
          currentAlarmText = F("Am Güterbahnhof");
          break;
     }
     case 43:
     {
          currentAlarmText = F("Am Steg");
          break;
     }
     case 46:
     {
          currentAlarmText = F("Am Stockhaus");
          break;
     }
     case 47:
     {
          currentAlarmText = F("Am Throms Garten");
          break;
     }
     case 48:
     {
          currentAlarmText = F("Am Unteren Rain");
          break;
     }
     case 54:
     {
          currentAlarmText = F("Am Zollstock");
          break;
     }
     case 55:
     {
          currentAlarmText = F("Amselweg");
          break;
     }
     case 59:
     {
          currentAlarmText = F("An der Alten Post");
          break;
     }
     case 60:
     {
          currentAlarmText = F("An der Automeile");
          break;
     }
     case 61:
     {
          currentAlarmText = F("An der Hessenhalle");
          break;
     }
     case 62:
     {
          currentAlarmText = F("An der Johanneskirche");
          break;
     }
     case 63:
     {
          currentAlarmText = F("An der Kaserne");
          break;
     }
     case 64:
     {
          currentAlarmText = F("An der Liebigshöhe");
          break;
     }
     case 67:
     {
          currentAlarmText = F("An der Volkshalle");
          break;
     }
     case 68:
     {
          currentAlarmText = F("An Steins Garten");
          break;
     }
     case 70:
     {
          currentAlarmText = F("Anger");
          break;
     }
     case 71:
     {
          currentAlarmText = F("Anna-Mettbach-Strasse");
          break;
     }
     case 72:
     {
          currentAlarmText = F("Anne-Frank-Strasse");
          break;
     }
     case 73:
     {
          currentAlarmText = F("Anneröder Weg");
          break;
     }
     case 74:
     {
          currentAlarmText = F("Annette-Kolb-Weg");
          break;
     }
     case 75:
     {
          currentAlarmText = F("Arndtstrasse");
          break;
     }
     case 76:
     {
          currentAlarmText = F("Asterweg");
          break;
     }
     case 81:
     {
          currentAlarmText = F("Auf der Bach");
          break;
     }
     case 83:
     {
          currentAlarmText = F("August-Balzer-Weg");
          break;
     }
     case 85:
     {
          currentAlarmText = F("August-Hermann-Francke-Weg");
          break;
     }
     case 86:
     {
          currentAlarmText = F("August-Messer-Strasse");
          break;
     }
     case 87:
     {
          currentAlarmText = F("Aulweg");
          break;
     }
     case 92:
     {
          currentAlarmText = F("Bahnhofstrasse");
          break;
     }
     case 93:
     {
          currentAlarmText = F("Bänningerstrasse");
          break;
     }
     case 94:
     {
          currentAlarmText = F("Bantzerweg");
          break;
     }
     case 96:
     {
          currentAlarmText = F("Barresgraben");
          break;
     }
     case 97:
     {
          currentAlarmText = F("Baumgarten");
          break;
     }
     case 99:
     {
          currentAlarmText = F("Beethovenstrasse");
          break;
     }
     case 102:
     {
          currentAlarmText = F("Bergwerk");
          break;
     }
     case 103:
     {
          currentAlarmText = F("Berliner Platz");
          break;
     }
     case 105:
     {
          currentAlarmText = F("Bernhard-Itzel-Strasse");
          break;
     }
     case 107:
     {
          currentAlarmText = F("Bertha-von-Suttner-Weg");
          break;
     }
     case 111:
     {
          currentAlarmText = F("Bismarckstrasse");
          break;
     }
     case 113:
     {
          currentAlarmText = F("Bleichstrasse");
          break;
     }
     case 114:
     {
          currentAlarmText = F("Böcklinstrasse");
          break;
     }
     case 115:
     {
          currentAlarmText = F("Bodelschwinghweg");
          break;
     }
     case 116:
     {
          currentAlarmText = F("Bonifatiusweg");
          break;
     }
     case 117:
     {
          currentAlarmText = F("Bootshausstrasse");
          break;
     }
     case 118:
     {
          currentAlarmText = F("Börneweg");
          break;
     }
     case 119:
     {
          currentAlarmText = F("Brahmsstrasse");
          break;
     }
     case 120:
     {
          currentAlarmText = F("Brandgasse");
          break;
     }
     case 121:
     {
          currentAlarmText = F("Brandplatz");
          break;
     }
     case 123:
     {
          currentAlarmText = F("Braugasse");
          break;
     }
     case 125:
     {
          currentAlarmText = F("Bromberger Strasse");
          break;
     }
     case 126:
     {
          currentAlarmText = F("Bruchstrasse");
          break;
     }
     case 128:
     {
          currentAlarmText = F("Brumlikweg");
          break;
     }
     case 131:
     {
          currentAlarmText = F("Buchenweg");
          break;
     }
     case 132:
     {
          currentAlarmText = F("Buchnerstrasse");
          break;
     }
     case 133:
     {
          currentAlarmText = F("Bückingstrasse");
          break;
     }
     case 134:
     {
          currentAlarmText = F("Buddestrasse");
          break;
     }
     case 139:
     {
          currentAlarmText = F("Burggraben");
          break;
     }
     case 142:
     {
          currentAlarmText = F("Carl-Franz-Strasse");
          break;
     }
     case 143:
     {
          currentAlarmText = F("Carl-Maria-von-Weber-Strasse");
          break;
     }
     case 144:
     {
          currentAlarmText = F("Carlo-Mierendorff-Strasse");
          break;
     }
     case 146:
     {
          currentAlarmText = F("Carl-Vogt-Strasse");
          break;
     }
     case 148:
     {
          currentAlarmText = F("Christian-Rinck-Strasse");
          break;
     }
     case 149:
     {
          currentAlarmText = F("Christoph-Rübsamen-Steg");
          break;
     }
     case 150:
     {
          currentAlarmText = F("Clementiastrasse");
          break;
     }
     case 151:
     {
          currentAlarmText = F("Clevelandstrasse");
          break;
     }
     case 152:
     {
          currentAlarmText = F("Colemanstrasse");
          break;
     }
     case 153:
     {
          currentAlarmText = F("Cranachstrasse");
          break;
     }
     case 154:
     {
          currentAlarmText = F("Crednerstrasse");
          break;
     }
     case 155:
     {
          currentAlarmText = F("Curtmannstrasse");
          break;
     }
     case 156:
     {
          currentAlarmText = F("Dahlienweg");
          break;
     }
     case 157:
     {
          currentAlarmText = F("Dammstrasse");
          break;
     }
     case 158:
     {
          currentAlarmText = F("Danziger Strasse");
          break;
     }
     case 161:
     {
          currentAlarmText = F("Dietrich-Bonhöffer-Strasse");
          break;
     }
     case 162:
     {
          currentAlarmText = F("Diezstrasse");
          break;
     }
     case 163:
     {
          currentAlarmText = F("Döringstrasse");
          break;
     }
     case 164:
     {
          currentAlarmText = F("Domäne Schiffenberg");
          break;
     }
     case 166:
     {
          currentAlarmText = F("Drosselweg");
          break;
     }
     case 168:
     {
          currentAlarmText = F("Dünsbergstrasse");
          break;
     }
     case 169:
     {
          currentAlarmText = F("Dürerstrasse");
          break;
     }
     case 171:
     {
          currentAlarmText = F("Ebelstrasse");
          break;
     }
     case 173:
     {
          currentAlarmText = F("Ederstrasse");
          break;
     }
     case 174:
     {
          currentAlarmText = F("Editha-Klipstein-Weg");
          break;
     }
     case 175:
     {
          currentAlarmText = F("Edlef-Köppen-Weg");
          break;
     }
     case 177:
     {
          currentAlarmText = F("Egerländer Strasse");
          break;
     }
     case 179:
     {
          currentAlarmText = F("Eichendorffring");
          break;
     }
     case 181:
     {
          currentAlarmText = F("Eichgärten");
          break;
     }
     case 182:
     {
          currentAlarmText = F("Eichgärtenallee");
          break;
     }
     case 186:
     {
          currentAlarmText = F("Elly-Heuss-Knapp-Weg");
          break;
     }
     case 187:
     {
          currentAlarmText = F("Elsa-Brandström-Strasse");
          break;
     }
     case 188:
     {
          currentAlarmText = F("Erdkauter Weg");
          break;
     }
     case 190:
     {
          currentAlarmText = F("Erlengasse");
          break;
     }
     case 192:
     {
          currentAlarmText = F("Ernst-Eckstein-Strasse");
          break;
     }
     case 193:
     {
          currentAlarmText = F("Ernst-Leitz-Strasse");
          break;
     }
     case 194:
     {
          currentAlarmText = F("Ernst-Toller-Weg");
          break;
     }
     case 195:
     {
          currentAlarmText = F("Eulenkopf");
          break;
     }
     case 196:
     {
          currentAlarmText = F("Europastrasse");
          break;
     }
     case 197:
     {
          currentAlarmText = F("Falkweg");
          break;
     }
     case 199:
     {
          currentAlarmText = F("Fasanenweg");
          break;
     }
     case 200:
     {
          currentAlarmText = F("Felsenweg");
          break;
     }
     case 201:
     {
          currentAlarmText = F("Ferniestrasse");
          break;
     }
     case 202:
     {
          currentAlarmText = F("Feuerbachstrasse");
          break;
     }
     case 203:
     {
          currentAlarmText = F("Feulgenstrasse");
          break;
     }
     case 204:
     {
          currentAlarmText = F("Fichtestrasse");
          break;
     }
     case 205:
     {
          currentAlarmText = F("Finkenweg");
          break;
     }
     case 206:
     {
          currentAlarmText = F("Fliednerweg");
          break;
     }
     case 208:
     {
          currentAlarmText = F("Flutgraben");
          break;
     }
     case 209:
     {
          currentAlarmText = F("Fockestrasse");
          break;
     }
     case 211:
     {
          currentAlarmText = F("Forsthausweg");
          break;
     }
     case 214:
     {
          currentAlarmText = F("Franzensbader Strasse");
          break;
     }
     case 215:
     {
          currentAlarmText = F("Freiligrathstrasse");
          break;
     }
     case 216:
     {
          currentAlarmText = F("Friedensstrasse");
          break;
     }
     case 217:
     {
          currentAlarmText = F("Friedhofsallee");
          break;
     }
     case 221:
     {
          currentAlarmText = F("Friedrich-List-Strasse");
          break;
     }
     case 222:
     {
          currentAlarmText = F("Friedrich-Naumann-Strasse");
          break;
     }
     case 223:
     {
          currentAlarmText = F("Friedrich-Schwarz-Strasse");
          break;
     }
     case 224:
     {
          currentAlarmText = F("Friedrichstrasse");
          break;
     }
     case 225:
     {
          currentAlarmText = F("Fröbelstrasse");
          break;
     }
     case 227:
     {
          currentAlarmText = F("Fuchsgraben");
          break;
     }
     case 228:
     {
          currentAlarmText = F("Fuldastrasse");
          break;
     }
     case 229:
     {
          currentAlarmText = F("Gabelsbergerstrasse");
          break;
     }
     case 230:
     {
          currentAlarmText = F("Gaffkystrasse");
          break;
     }
     case 232:
     {
          currentAlarmText = F("Gartenstrasse");
          break;
     }
     case 233:
     {
          currentAlarmText = F("Gartfeld");
          break;
     }
     case 235:
     {
          currentAlarmText = F("Georg-Büchner-Strasse");
          break;
     }
     case 237:
     {
          currentAlarmText = F("Georg-Elser-Strasse");
          break;
     }
     case 238:
     {
          currentAlarmText = F("Georg-Haas-Strasse");
          break;
     }
     case 239:
     {
          currentAlarmText = F("Georg-Philipp-Gail-Strasse");
          break;
     }
     case 240:
     {
          currentAlarmText = F("Georg-Schlosser-Strasse");
          break;
     }
     case 242:
     {
          currentAlarmText = F("Geranienweg");
          break;
     }
     case 246:
     {
          currentAlarmText = F("Glaubrechtstrasse");
          break;
     }
     case 247:
     {
          currentAlarmText = F("Gleiberger Weg");
          break;
     }
     case 249:
     {
          currentAlarmText = F("Gnauthstrasse");
          break;
     }
     case 250:
     {
          currentAlarmText = F("Göthestrasse");
          break;
     }
     case 252:
     {
          currentAlarmText = F("Gottfried-Arnold-Strasse");
          break;
     }
     case 253:
     {
          currentAlarmText = F("Gottlieb-Daimler-Strasse");
          break;
     }
     case 255:
     {
          currentAlarmText = F("Graudenzer Strasse");
          break;
     }
     case 258:
     {
          currentAlarmText = F("Grenzborn");
          break;
     }
     case 261:
     {
          currentAlarmText = F("Grosser Morgen");
          break;
     }
     case 262:
     {
          currentAlarmText = F("Grosser Steinweg");
          break;
     }
     case 263:
     {
          currentAlarmText = F("Grünberger Strasse");
          break;
     }
     case 264:
     {
          currentAlarmText = F("Grüner Weg");
          break;
     }
     case 265:
     {
          currentAlarmText = F("Günthersgraben");
          break;
     }
     case 266:
     {
          currentAlarmText = F("Gustav-Krüger-Strasse");
          break;
     }
     case 268:
     {
          currentAlarmText = F("Gutenbergstrasse");
          break;
     }
     case 269:
     {
          currentAlarmText = F("Gutfleischstrasse");
          break;
     }
     case 271:
     {
          currentAlarmText = F("Hammstrasse");
          break;
     }
     case 272:
     {
          currentAlarmText = F("Händelstrasse");
          break;
     }
     case 275:
     {
          currentAlarmText = F("Hannah-Arendt-Strasse");
          break;
     }
     case 276:
     {
          currentAlarmText = F("Hardtallee");
          break;
     }
     case 277:
     {
          currentAlarmText = F("Hasenköppel");
          break;
     }
     case 278:
     {
          currentAlarmText = F("Hasenpfad");
          break;
     }
     case 280:
     {
          currentAlarmText = F("Häuser Born");
          break;
     }
     case 281:
     {
          currentAlarmText = F("Haydnstrasse");
          break;
     }
     case 282:
     {
          currentAlarmText = F("Hedwig-Burgheim-Ring");
          break;
     }
     case 283:
     {
          currentAlarmText = F("Heegstrauchweg");
          break;
     }
     case 287:
     {
          currentAlarmText = F("Hein-Heckroth-Strasse");
          break;
     }
     case 288:
     {
          currentAlarmText = F("Heinrich-Buff-Ring");
          break;
     }
     case 289:
     {
          currentAlarmText = F("Heinrich-Fourier-Strasse");
          break;
     }
     case 291:
     {
          currentAlarmText = F("Heinrich-Will-Strasse");
          break;
     }
     case 292:
     {
          currentAlarmText = F("Helene-Weber-Weg");
          break;
     }
     case 294:
     {
          currentAlarmText = F("Henriette-Fürth-Strasse");
          break;
     }
     case 295:
     {
          currentAlarmText = F("Henriette-Hezel-Strasse");
          break;
     }
     case 296:
     {
          currentAlarmText = F("Henselstrasse");
          break;
     }
     case 297:
     {
          currentAlarmText = F("Herderweg");
          break;
     }
     case 298:
     {
          currentAlarmText = F("Hermann-Levi-Strasse");
          break;
     }
     case 301:
     {
          currentAlarmText = F("Hessenstrasse");
          break;
     }
     case 302:
     {
          currentAlarmText = F("Heuchelheimer Strasse");
          break;
     }
     case 303:
     {
          currentAlarmText = F("Heyerweg");
          break;
     }
     case 304:
     {
          currentAlarmText = F("Hillebrandstrasse");
          break;
     }
     case 305:
     {
          currentAlarmText = F("Hindemithstrasse");
          break;
     }
     case 307:
     {
          currentAlarmText = F("Hinter der Ostanlage");
          break;
     }
     case 308:
     {
          currentAlarmText = F("Hinter der Westanlage");
          break;
     }
     case 312:
     {
          currentAlarmText = F("Hochwarte");
          break;
     }
     case 313:
     {
          currentAlarmText = F("Hofacker");
          break;
     }
     case 314:
     {
          currentAlarmText = F("Hofmannstrasse");
          break;
     }
     case 317:
     {
          currentAlarmText = F("Hoher Rain");
          break;
     }
     case 319:
     {
          currentAlarmText = F("Holbeinring");
          break;
     }
     case 321:
     {
          currentAlarmText = F("Hollerweg");
          break;
     }
     case 323:
     {
          currentAlarmText = F("Holzweg");
          break;
     }
     case 325:
     {
          currentAlarmText = F("Hornackerring");
          break;
     }
     case 328:
     {
          currentAlarmText = F("Hugo-von-Ritgen-Strasse");
          break;
     }
     case 329:
     {
          currentAlarmText = F("Hultschiner Strasse");
          break;
     }
     case 330:
     {
          currentAlarmText = F("Humboldtstrasse");
          break;
     }
     case 331:
     {
          currentAlarmText = F("Hunfeld");
          break;
     }
     case 333:
     {
          currentAlarmText = F("Hüttenweg");
          break;
     }
     case 334:
     {
          currentAlarmText = F("Iheringstrasse");
          break;
     }
     case 338:
     {
          currentAlarmText = F("Im Kalten Grund");
          break;
     }
     case 346:
     {
          currentAlarmText = F("In der Lechenau");
          break;
     }
     case 350:
     {
          currentAlarmText = F("Jacksonstrasse");
          break;
     }
     case 351:
     {
          currentAlarmText = F("Jahnstrasse");
          break;
     }
     case 352:
     {
          currentAlarmText = F("Jefferson Street");
          break;
     }
     case 354:
     {
          currentAlarmText = F("Joachimstaler Strasse");
          break;
     }
     case 355:
     {
          currentAlarmText = F("Johann-Bernhard-Wilbrand-Strasse");
          break;
     }
     case 356:
     {
          currentAlarmText = F("Johannesbader Strasse");
          break;
     }
     case 358:
     {
          currentAlarmText = F("Johannesstrasse");
          break;
     }
     case 359:
     {
          currentAlarmText = F("Johannette-Lein-Gasse");
          break;
     }
     case 360:
     {
          currentAlarmText = F("Johann-Sebastian-Bach-Strasse");
          break;
     }
     case 361:
     {
          currentAlarmText = F("John-F.-Kennedy-Platz");
          break;
     }
     case 362:
     {
          currentAlarmText = F("Joseph-Kreuter-Weg");
          break;
     }
     case 363:
     {
          currentAlarmText = F("Julius-Höpfner-Strasse");
          break;
     }
     case 365:
     {
          currentAlarmText = F("Junkersstrasse");
          break;
     }
     case 368:
     {
          currentAlarmText = F("Kantstrasse");
          break;
     }
     case 369:
     {
          currentAlarmText = F("Kanzleiberg");
          break;
     }
     case 370:
     {
          currentAlarmText = F("Kapellenstrasse");
          break;
     }
     case 371:
     {
          currentAlarmText = F("Kaplansgasse");
          break;
     }
     case 373:
     {
          currentAlarmText = F("Karl-Benz-Strasse");
          break;
     }
     case 374:
     {
          currentAlarmText = F("Karl-Follen-Strasse");
          break;
     }
     case 375:
     {
          currentAlarmText = F("Karl-Glöckner-Strasse");
          break;
     }
     case 376:
     {
          currentAlarmText = F("Karl-Keller-Strasse");
          break;
     }
     case 378:
     {
          currentAlarmText = F("Karl-Reuter-Weg");
          break;
     }
     case 379:
     {
          currentAlarmText = F("Karl-Sack-Strasse");
          break;
     }
     case 380:
     {
          currentAlarmText = F("Karlsbader Strasse");
          break;
     }
     case 382:
     {
          currentAlarmText = F("Katharinengasse");
          break;
     }
     case 383:
     {
          currentAlarmText = F("Katharinenplatz");
          break;
     }
     case 385:
     {
          currentAlarmText = F("Keplerstrasse");
          break;
     }
     case 386:
     {
          currentAlarmText = F("Kerkrader Strasse");
          break;
     }
     case 389:
     {
          currentAlarmText = F("Kirchenplatz");
          break;
     }
     case 394:
     {
          currentAlarmText = F("Kirschbaumweg");
          break;
     }
     case 397:
     {
          currentAlarmText = F("Kleine Mühlgasse");
          break;
     }
     case 399:
     {
          currentAlarmText = F("Klingelbachweg");
          break;
     }
     case 400:
     {
          currentAlarmText = F("Klinikstrasse");
          break;
     }
     case 401:
     {
          currentAlarmText = F("Klosterweg");
          break;
     }
     case 403:
     {
          currentAlarmText = F("Königgrätzer Strasse");
          break;
     }
     case 404:
     {
          currentAlarmText = F("Konstantinbader Strasse");
          break;
     }
     case 407:
     {
          currentAlarmText = F("Kreuzplatz");
          break;
     }
     case 408:
     {
          currentAlarmText = F("Krofdorfer Strasse");
          break;
     }
     case 409:
     {
          currentAlarmText = F("Kropbacher Weg");
          break;
     }
     case 411:
     {
          currentAlarmText = F("Kugelberg");
          break;
     }
     case 413:
     {
          currentAlarmText = F("Lahnstrasse");
          break;
     }
     case 414:
     {
          currentAlarmText = F("Landgrafenstrasse");
          break;
     }
     case 415:
     {
          currentAlarmText = F("Landgraf-Philipp-Platz");
          break;
     }
     case 416:
     {
          currentAlarmText = F("Landmannstrasse");
          break;
     }
     case 419:
     {
          currentAlarmText = F("Langhansstrasse");
          break;
     }
     case 420:
     {
          currentAlarmText = F("Lärchenwäldchen");
          break;
     }
     case 421:
     {
          currentAlarmText = F("Läufertsröder Weg");
          break;
     }
     case 422:
     {
          currentAlarmText = F("Launsbacher Weg");
          break;
     }
     case 423:
     {
          currentAlarmText = F("Lausköppel");
          break;
     }
     case 424:
     {
          currentAlarmText = F("Lehmweg");
          break;
     }
     case 425:
     {
          currentAlarmText = F("Leihgesterner Weg");
          break;
     }
     case 426:
     {
          currentAlarmText = F("Leimenkauter Weg");
          break;
     }
     case 427:
     {
          currentAlarmText = F("Lessingstrasse");
          break;
     }
     case 428:
     {
          currentAlarmText = F("Licher Strasse");
          break;
     }
     case 430:
     {
          currentAlarmText = F("Liebigstrasse");
          break;
     }
     case 431:
     {
          currentAlarmText = F("Lilienthalstrasse");
          break;
     }
     case 432:
     {
          currentAlarmText = F("Lilienweg");
          break;
     }
     case 433:
     {
          currentAlarmText = F("Lincolnstrasse");
          break;
     }
     case 434:
     {
          currentAlarmText = F("Lindengasse");
          break;
     }
     case 435:
     {
          currentAlarmText = F("Lindenplatz");
          break;
     }
     case 437:
     {
          currentAlarmText = F("Löbers Hof");
          break;
     }
     case 438:
     {
          currentAlarmText = F("Löberstrasse");
          break;
     }
     case 439:
     {
          currentAlarmText = F("Lonystrasse");
          break;
     }
     case 440:
     {
          currentAlarmText = F("Louis-Frech-Strasse");
          break;
     }
     case 441:
     {
          currentAlarmText = F("Löwengasse");
          break;
     }
     case 442:
     {
          currentAlarmText = F("Ludwig-Richter-Strasse");
          break;
     }
     case 443:
     {
          currentAlarmText = F("Ludwig-Schneider-Weg");
          break;
     }
     case 444:
     {
          currentAlarmText = F("Ludwigsplatz");
          break;
     }
     case 445:
     {
          currentAlarmText = F("Ludwigstrasse");
          break;
     }
     case 446:
     {
          currentAlarmText = F("Lufthansastrasse");
          break;
     }
     case 447:
     {
          currentAlarmText = F("Lutherberg");
          break;
     }
     case 449:
     {
          currentAlarmText = F("Maigasse");
          break;
     }
     case 450:
     {
          currentAlarmText = F("Marburger Strasse");
          break;
     }
     case 451:
     {
          currentAlarmText = F("Margarete-Bieber-Weg");
          break;
     }
     case 452:
     {
          currentAlarmText = F("Margaretenhütte");
          break;
     }
     case 453:
     {
          currentAlarmText = F("Maria-Birnbaum-Weg");
          break;
     }
     case 454:
     {
          currentAlarmText = F("Marie-Curie-Weg");
          break;
     }
     case 455:
     {
          currentAlarmText = F("Marie-Juchacz-Weg");
          break;
     }
     case 456:
     {
          currentAlarmText = F("Marienbader Strasse");
          break;
     }
     case 457:
     {
          currentAlarmText = F("Marktlaubenstrasse");
          break;
     }
     case 458:
     {
          currentAlarmText = F("Marktplatz");
          break;
     }
     case 459:
     {
          currentAlarmText = F("Marktstrasse");
          break;
     }
     case 461:
     {
          currentAlarmText = F("Marshallstrasse");
          break;
     }
     case 463:
     {
          currentAlarmText = F("Martin-Luther-King-Strasse");
          break;
     }
     case 464:
     {
          currentAlarmText = F("Mäusburg");
          break;
     }
     case 465:
     {
          currentAlarmText = F("Max-Eyth-Strasse");
          break;
     }
     case 466:
     {
          currentAlarmText = F("Max-Reger-Strasse");
          break;
     }
     case 467:
     {
          currentAlarmText = F("Meerweinstrasse");
          break;
     }
     case 469:
     {
          currentAlarmText = F("Meisenbornweg");
          break;
     }
     case 471:
     {
          currentAlarmText = F("Memeler Strasse");
          break;
     }
     case 472:
     {
          currentAlarmText = F("Menzelstrasse");
          break;
     }
     case 473:
     {
          currentAlarmText = F("Mildred-Harnack-Weg");
          break;
     }
     case 474:
     {
          currentAlarmText = F("Minna-Naumann-Weg");
          break;
     }
     case 475:
     {
          currentAlarmText = F("Mittelweg");
          break;
     }
     case 476:
     {
          currentAlarmText = F("Mittermaierstrasse");
          break;
     }
     case 477:
     {
          currentAlarmText = F("Mohrunger Weg");
          break;
     }
     case 478:
     {
          currentAlarmText = F("Moltkestrasse");
          break;
     }
     case 479:
     {
          currentAlarmText = F("Monroestrasse");
          break;
     }
     case 482:
     {
          currentAlarmText = F("Mozartstrasse");
          break;
     }
     case 485:
     {
          currentAlarmText = F("Mühlstrasse");
          break;
     }
     case 486:
     {
          currentAlarmText = F("Nahrungsberg");
          break;
     }
     case 487:
     {
          currentAlarmText = F("Narzissenweg");
          break;
     }
     case 488:
     {
          currentAlarmText = F("Nelkenweg");
          break;
     }
     case 489:
     {
          currentAlarmText = F("Nelly-Sachs-Weg");
          break;
     }
     case 490:
     {
          currentAlarmText = F("Netanyastrasse");
          break;
     }
     case 492:
     {
          currentAlarmText = F("Neuen Bäue");
          break;
     }
     case 493:
     {
          currentAlarmText = F("Neuenweg");
          break;
     }
     case 494:
     {
          currentAlarmText = F("Neustadt");
          break;
     }
     case 497:
     {
          currentAlarmText = F("Nonnenweg");
          break;
     }
     case 498:
     {
          currentAlarmText = F("Nordanlage");
          break;
     }
     case 500:
     {
          currentAlarmText = F("Oberauweg");
          break;
     }
     case 501:
     {
          currentAlarmText = F("Oberer Gleiberger Weg");
          break;
     }
     case 502:
     {
          currentAlarmText = F("Oberer Hardthof");
          break;
     }
     case 506:
     {
          currentAlarmText = F("Oberlinweg");
          break;
     }
     case 508:
     {
          currentAlarmText = F("Ohlebergsweg");
          break;
     }
     case 509:
     {
          currentAlarmText = F("Ostanlage");
          break;
     }
     case 510:
     {
          currentAlarmText = F("Oswaldsgarten");
          break;
     }
     case 511:
     {
          currentAlarmText = F("Otto-Behaghel-Strasse");
          break;
     }
     case 512:
     {
          currentAlarmText = F("Pater-Delp-Strasse");
          break;
     }
     case 513:
     {
          currentAlarmText = F("Paul-Meimberg-Strasse");
          break;
     }
     case 514:
     {
          currentAlarmText = F("Paul-Schneider-Strasse");
          break;
     }
     case 515:
     {
          currentAlarmText = F("Paul-Zipp-Strasse");
          break;
     }
     case 516:
     {
          currentAlarmText = F("Pestalozzistrasse");
          break;
     }
     case 517:
     {
          currentAlarmText = F("Petersweiher");
          break;
     }
     case 518:
     {
          currentAlarmText = F("Pfarrgarten");
          break;
     }
     case 520:
     {
          currentAlarmText = F("Philipp-Reis-Strasse");
          break;
     }
     case 523:
     {
          currentAlarmText = F("Philosophenwald");
          break;
     }
     case 524:
     {
          currentAlarmText = F("Pistorstrasse");
          break;
     }
     case 525:
     {
          currentAlarmText = F("Platz der Deutschen Einheit");
          break;
     }
     case 526:
     {
          currentAlarmText = F("Plockstrasse");
          break;
     }
     case 527:
     {
          currentAlarmText = F("Pohlheimer Strasse");
          break;
     }
     case 528:
     {
          currentAlarmText = F("Posener Strasse");
          break;
     }
     case 529:
     {
          currentAlarmText = F("Professorenweg");
          break;
     }
     case 531:
     {
          currentAlarmText = F("Rabenweg");
          break;
     }
     case 532:
     {
          currentAlarmText = F("Raiffeisenstrasse");
          break;
     }
     case 533:
     {
          currentAlarmText = F("Rambachweg");
          break;
     }
     case 534:
     {
          currentAlarmText = F("Rathenaustrasse");
          break;
     }
     case 536:
     {
          currentAlarmText = F("Rehschneise");
          break;
     }
     case 538:
     {
          currentAlarmText = F("Reichenberger Strasse");
          break;
     }
     case 539:
     {
          currentAlarmText = F("Reichensand");
          break;
     }
     case 542:
     {
          currentAlarmText = F("Richard-Schirrmann-Weg");
          break;
     }
     case 543:
     {
          currentAlarmText = F("Richard-Wagner-Strasse");
          break;
     }
     case 544:
     {
          currentAlarmText = F("Riegelpfad");
          break;
     }
     case 546:
     {
          currentAlarmText = F("Ringallee");
          break;
     }
     case 547:
     {
          currentAlarmText = F("Rittergasse");
          break;
     }
     case 548:
     {
          currentAlarmText = F("Riversplatz");
          break;
     }
     case 549:
     {
          currentAlarmText = F("Robert-Bosch-Strasse");
          break;
     }
     case 550:
     {
          currentAlarmText = F("Robert-Sommer-Strasse");
          break;
     }
     case 551:
     {
          currentAlarmText = F("Röderring");
          break;
     }
     case 552:
     {
          currentAlarmText = F("Rödgener Strasse");
          break;
     }
     case 553:
     {
          currentAlarmText = F("Rodheimer Strasse");
          break;
     }
     case 554:
     {
          currentAlarmText = F("Rodtbergstrasse");
          break;
     }
     case 555:
     {
          currentAlarmText = F("Rodtgärten");
          break;
     }
     case 556:
     {
          currentAlarmText = F("Rodthohl");
          break;
     }
     case 557:
     {
          currentAlarmText = F("Röntgenstrasse");
          break;
     }
     case 558:
     {
          currentAlarmText = F("Roonstrasse");
          break;
     }
     case 559:
     {
          currentAlarmText = F("Rooseveltstrasse");
          break;
     }
     case 561:
     {
          currentAlarmText = F("Rosenpfad");
          break;
     }
     case 563:
     {
          currentAlarmText = F("Rudolf-Buchheim-Strasse");
          break;
     }
     case 564:
     {
          currentAlarmText = F("Rudolf-Diesel-Strasse");
          break;
     }
     case 567:
     {
          currentAlarmText = F("Salomestrasse");
          break;
     }
     case 568:
     {
          currentAlarmText = F("Salzböder Weg");
          break;
     }
     case 570:
     {
          currentAlarmText = F("Sandfeld");
          break;
     }
     case 571:
     {
          currentAlarmText = F("Sandgasse");
          break;
     }
     case 572:
     {
          currentAlarmText = F("Sandkauter Weg");
          break;
     }
     case 573:
     {
          currentAlarmText = F("Schäferbrunnen");
          break;
     }
     case 574:
     {
          currentAlarmText = F("Schanzenstrasse");
          break;
     }
     case 575:
     {
          currentAlarmText = F("Schiessgärten");
          break;
     }
     case 576:
     {
          currentAlarmText = F("Schiffenberger Weg");
          break;
     }
     case 578:
     {
          currentAlarmText = F("Schillerstrasse");
          break;
     }
     case 579:
     {
          currentAlarmText = F("Schlachthofstrasse");
          break;
     }
     case 580:
     {
          currentAlarmText = F("Schlangenzahl");
          break;
     }
     case 582:
     {
          currentAlarmText = F("Schlesische Strasse");
          break;
     }
     case 583:
     {
          currentAlarmText = F("Schlossgasse");
          break;
     }
     case 587:
     {
          currentAlarmText = F("Schottstrasse");
          break;
     }
     case 588:
     {
          currentAlarmText = F("Schubertstrasse");
          break;
     }
     case 589:
     {
          currentAlarmText = F("Schulstrasse");
          break;
     }
     case 590:
     {
          currentAlarmText = F("Schuppstrasse");
          break;
     }
     case 592:
     {
          currentAlarmText = F("Schützenstrasse");
          break;
     }
     case 593:
     {
          currentAlarmText = F("Schwalbachacker");
          break;
     }
     case 594:
     {
          currentAlarmText = F("Schwarzacker");
          break;
     }
     case 596:
     {
          currentAlarmText = F("Schwarzlachweg");
          break;
     }
     case 600:
     {
          currentAlarmText = F("Seltersweg");
          break;
     }
     case 601:
     {
          currentAlarmText = F("Senckenbergstrasse");
          break;
     }
     case 602:
     {
          currentAlarmText = F("Sieboldstrasse");
          break;
     }
     case 603:
     {
          currentAlarmText = F("Siegmund-Heichelheim-Strasse");
          break;
     }
     case 604:
     {
          currentAlarmText = F("Siemensstrasse");
          break;
     }
     case 605:
     {
          currentAlarmText = F("Sommerberg");
          break;
     }
     case 606:
     {
          currentAlarmText = F("Sonnenstrasse");
          break;
     }
     case 608:
     {
          currentAlarmText = F("Spenerweg");
          break;
     }
     case 609:
     {
          currentAlarmText = F("Spitzwegring");
          break;
     }
     case 610:
     {
          currentAlarmText = F("Spörhasestrasse");
          break;
     }
     case 613:
     {
          currentAlarmText = F("Stadtwald");
          break;
     }
     case 614:
     {
          currentAlarmText = F("Starenweg");
          break;
     }
     case 616:
     {
          currentAlarmText = F("Stefan-Bellof-Strasse");
          break;
     }
     case 618:
     {
          currentAlarmText = F("Steinberger Weg");
          break;
     }
     case 621:
     {
          currentAlarmText = F("Steinkaute");
          break;
     }
     case 622:
     {
          currentAlarmText = F("Steinstrasse");
          break;
     }
     case 623:
     {
          currentAlarmText = F("Stephanstrasse");
          break;
     }
     case 624:
     {
          currentAlarmText = F("Sternmark");
          break;
     }
     case 626:
     {
          currentAlarmText = F("Stolzenmorgen");
          break;
     }
     case 630:
     {
          currentAlarmText = F("Studentensteg");
          break;
     }
     case 631:
     {
          currentAlarmText = F("Südanlage");
          break;
     }
     case 632:
     {
          currentAlarmText = F("Sudetenlandstrasse");
          break;
     }
     case 633:
     {
          currentAlarmText = F("Südhang");
          break;
     }
     case 634:
     {
          currentAlarmText = F("Talstrasse");
          break;
     }
     case 635:
     {
          currentAlarmText = F("Tannenweg");
          break;
     }
     case 636:
     {
          currentAlarmText = F("Taubenweg");
          break;
     }
     case 640:
     {
          currentAlarmText = F("Teufelslustgärtchen");
          break;
     }
     case 641:
     {
          currentAlarmText = F("Thärstrasse");
          break;
     }
     case 642:
     {
          currentAlarmText = F("Theodor-Storm-Weg");
          break;
     }
     case 643:
     {
          currentAlarmText = F("Therese-Kalbfleisch-Strasse");
          break;
     }
     case 644:
     {
          currentAlarmText = F("Thielmannweg");
          break;
     }
     case 645:
     {
          currentAlarmText = F("Thomastrasse");
          break;
     }
     case 646:
     {
          currentAlarmText = F("Tiefenweg");
          break;
     }
     case 648:
     {
          currentAlarmText = F("Trieb");
          break;
     }
     case 650:
     {
          currentAlarmText = F("Trillergässchen");
          break;
     }
     case 652:
     {
          currentAlarmText = F("Troppauer Strasse");
          break;
     }
     case 653:
     {
          currentAlarmText = F("Tulpenweg");
          break;
     }
     case 655:
     {
          currentAlarmText = F("Ubbelohdeweg");
          break;
     }
     case 658:
     {
          currentAlarmText = F("Uferweg");
          break;
     }
     case 659:
     {
          currentAlarmText = F("Uhlandstrasse");
          break;
     }
     case 660:
     {
          currentAlarmText = F("Ulner Dreieck");
          break;
     }
     case 661:
     {
          currentAlarmText = F("Unterer Hardthof");
          break;
     }
     case 663:
     {
          currentAlarmText = F("Unterhof");
          break;
     }
     case 664:
     {
          currentAlarmText = F("Unterm Hardtwäldchen");
          break;
     }
     case 666:
     {
          currentAlarmText = F("Versailler Strasse");
          break;
     }
     case 667:
     {
          currentAlarmText = F("Vetzberger Weg");
          break;
     }
     case 672:
     {
          currentAlarmText = F("Waagengasse");
          break;
     }
     case 674:
     {
          currentAlarmText = F("Waldbrunnenweg");
          break;
     }
     case 678:
     {
          currentAlarmText = F("Walltorstrasse");
          break;
     }
     case 679:
     {
          currentAlarmText = F("Walter-Süskind-Strasse");
          break;
     }
     case 680:
     {
          currentAlarmText = F("Wartweg");
          break;
     }
     case 681:
     {
          currentAlarmText = F("Washingtonstrasse");
          break;
     }
     case 682:
     {
          currentAlarmText = F("Watzenborner Weg");
          break;
     }
     case 683:
     {
          currentAlarmText = F("Weidengasse");
          break;
     }
     case 686:
     {
          currentAlarmText = F("Weilburger Grenze");
          break;
     }
     case 689:
     {
          currentAlarmText = F("Weisserde");
          break;
     }
     case 690:
     {
          currentAlarmText = F("Welckerstrasse");
          break;
     }
     case 693:
     {
          currentAlarmText = F("Werrastrasse");
          break;
     }
     case 694:
     {
          currentAlarmText = F("Weserstrasse");
          break;
     }
     case 695:
     {
          currentAlarmText = F("Westanlage");
          break;
     }
     case 696:
     {
          currentAlarmText = F("Wettenberger Weg");
          break;
     }
     case 699:
     {
          currentAlarmText = F("Wetzsteinstrasse");
          break;
     }
     case 700:
     {
          currentAlarmText = F("Wichernweg");
          break;
     }
     case 701:
     {
          currentAlarmText = F("Wiesecker Weg");
          break;
     }
     case 702:
     {
          currentAlarmText = F("Wiesenstrasse");
          break;
     }
     case 704:
     {
          currentAlarmText = F("Wilhelm-Leuschner-Strasse");
          break;
     }
     case 706:
     {
          currentAlarmText = F("Wilhelm-Pfeiffer-Strasse");
          break;
     }
     case 707:
     {
          currentAlarmText = F("Wilhelmstrasse");
          break;
     }
     case 708:
     {
          currentAlarmText = F("Wilsonstrasse");
          break;
     }
     case 709:
     {
          currentAlarmText = F("Winchester Strasse");
          break;
     }
     case 712:
     {
          currentAlarmText = F("Wingertshecke");
          break;
     }
     case 713:
     {
          currentAlarmText = F("Wissmarer Weg");
          break;
     }
     case 714:
     {
          currentAlarmText = F("Wolfstrasse");
          break;
     }
     case 715:
     {
          currentAlarmText = F("Wolkengasse");
          break;
     }
     case 716:
     {
          currentAlarmText = F("Zeppelinstrasse");
          break;
     }
     case 717:
     {
          currentAlarmText = F("Zinzendorfweg");
          break;
     }
     case 718:
     {
          currentAlarmText = F("Zu den Mühlen");
          break;
     }
     case 723:
     {
          currentAlarmText = F("Zum Waldsportplatz");
          break;
     }
     case 726:
     {
          currentAlarmText = F("Zur Grossen Bleiche");
          break;
     }
     // Kleinlinden
     case 5:
     {
          currentAlarmText = F("Albert-Bossler-Strasse");
          break;
     }
     case 10:
     {
          currentAlarmText = F("Allendorfer Strasse");
          break;
     }
     case 57:
     {
          currentAlarmText = F("An den Birken");
          break;
     }
     case 58:
     {
          currentAlarmText = F("An den Schulgärten");
          break;
     }
     case 69:
     {
          currentAlarmText = F("Andreasteich");
          break;
     }
     case 82:
     {
          currentAlarmText = F("Auf der Wann");
          break;
     }
     case 88:
     {
          currentAlarmText = F("Bachweg");
          break;
     }
     case 98:
     {
          currentAlarmText = F("Bechsteinweg");
          break;
     }
     case 101:
     {
          currentAlarmText = F("Bergwaldstrasse");
          break;
     }
     case 106:
     {
          currentAlarmText = F("Bernhardtstrasse");
          break;
     }
     case 109:
     {
          currentAlarmText = F("Bettina-von-Arnim-Strasse");
          break;
     }
     case 122:
     {
          currentAlarmText = F("Brandweg");
          break;
     }
     case 127:
     {
          currentAlarmText = F("Brüder-Grimm-Strasse");
          break;
     }
     case 137:
     {
          currentAlarmText = F("Bürgermeister-Jung-Weg");
          break;
     }
     case 138:
     {
          currentAlarmText = F("Burggartenstrasse");
          break;
     }
     case 210:
     {
          currentAlarmText = F("Fontaneweg");
          break;
     }
     case 212:
     {
          currentAlarmText = F("Frankfurter Strasse");
          break;
     }
     case 219:
     {
          currentAlarmText = F("Friedhofsweg");
          break;
     }
     case 236:
     {
          currentAlarmText = F("Georg-Edward-Strasse");
          break;
     }
     case 245:
     {
          currentAlarmText = F("Ginsterbusch");
          break;
     }
     case 256:
     {
          currentAlarmText = F("Gregor-Mendel-Strasse");
          break;
     }
     case 279:
     {
          currentAlarmText = F("Hauffstrasse");
          break;
     }
     case 284:
     {
          currentAlarmText = F("Heerweg");
          break;
     }
     case 285:
     {
          currentAlarmText = F("Hegweg");
          break;
     }
     case 286:
     {
          currentAlarmText = F("Heide");
          break;
     }
     case 299:
     {
          currentAlarmText = F("Hermann-Löns-Strasse");
          break;
     }
     case 300:
     {
          currentAlarmText = F("Hermann-Rau-Strasse");
          break;
     }
     case 318:
     {
          currentAlarmText = F("Hohl");
          break;
     }
     case 322:
     {
          currentAlarmText = F("Holunderweg");
          break;
     }
     case 327:
     {
          currentAlarmText = F("Hügelstrasse");
          break;
     }
     case 384:
     {
          currentAlarmText = F("Katzenbach");
          break;
     }
     case 391:
     {
          currentAlarmText = F("Kirchpfad");
          break;
     }
     case 448:
     {
          currentAlarmText = F("Lützellindener Strasse");
          break;
     }
     case 460:
     {
          currentAlarmText = F("Markwald");
          break;
     }
     case 480:
     {
          currentAlarmText = F("Moosweg");
          break;
     }
     case 495:
     {
          currentAlarmText = F("Niebergallweg");
          break;
     }
     case 519:
     {
          currentAlarmText = F("Pfingstweide");
          break;
     }
     case 545:
     {
          currentAlarmText = F("Riehlweg");
          break;
     }
     case 566:
     {
          currentAlarmText = F("Saarlandstrasse");
          break;
     }
     case 577:
     {
          currentAlarmText = F("Schildberg");
          break;
     }
     case 581:
     {
          currentAlarmText = F("Schlehdorn");
          break;
     }
     case 611:
     {
          currentAlarmText = F("Sportfeld");
          break;
     }
     case 673:
     {
          currentAlarmText = F("Wacholderbusch");
          break;
     }
     case 677:
     {
          currentAlarmText = F("Waldweide");
          break;
     }
     case 685:
     {
          currentAlarmText = F("Weigelstrasse");
          break;
     }
     case 698:
     {
          currentAlarmText = F("Wetzlarer Strasse");
          break;
     }
     case 703:
     {
          currentAlarmText = F("Wilhelm-Jung-Strasse");
          break;
     }
     case 722:
     {
          currentAlarmText = F("Zum Maiplatz");
          break;
     }
     case 724:
     {
          currentAlarmText = F("Zum Weiher");
          break;
     }
     //Lützellinden
     case 9:
     {
          currentAlarmText = F("Allendörfer Au");
          break;
     }
     case 26:
     {
          currentAlarmText = F("Am Backhaus");
          break;
     }
     case 32:
     {
          currentAlarmText = F("Am Faltergarten");
          break;
     }
     case 35:
     {
          currentAlarmText = F("Am Hellerpfad");
          break;
     }
     case 36:
     {
          currentAlarmText = F("Am Hügel");
          break;
     }
     case 42:
     {
          currentAlarmText = F("Am Steckelchen");
          break;
     }
     case 45:
     {
          currentAlarmText = F("Am Steinrück");
          break;
     }
     case 51:
     {
          currentAlarmText = F("Am Weiher");
          break;
     }
     case 66:
     {
          currentAlarmText = F("An der Schule");
          break;
     }
     case 104:
     {
          currentAlarmText = F("Berliner Strasse");
          break;
     }
     case 108:
     {
          currentAlarmText = F("Beskidenstrasse");
          break;
     }
     case 110:
     {
          currentAlarmText = F("Birkenweg");
          break;
     }
     case 112:
     {
          currentAlarmText = F("Bitzenstrasse");
          break;
     }
     case 124:
     {
          currentAlarmText = F("Breslauer Strasse");
          break;
     }
     case 170:
     {
          currentAlarmText = F("Dutenhofener Strasse");
          break;
     }
     case 198:
     {
          currentAlarmText = F("Falltorstrasse");
          break;
     }
     case 207:
     {
          currentAlarmText = F("Flugplatz");
          break;
     }
     case 213:
     {
          currentAlarmText = F("Franzen Garten");
          break;
     }
     case 226:
     {
          currentAlarmText = F("Fröschen Weiher");
          break;
     }
     case 259:
     {
          currentAlarmText = F("Grethenstrasse");
          break;
     }
     case 306:
     {
          currentAlarmText = F("Hinter dem Steinrücken");
          break;
     }
     case 310:
     {
          currentAlarmText = F("Hochelheimer Weg");
          break;
     }
     case 326:
     {
          currentAlarmText = F("Hörnsheimer Strasse");
          break;
     }
     case 335:
     {
          currentAlarmText = F("Im Gässchen");
          break;
     }
     case 340:
     {
          currentAlarmText = F("Im Sporn");
          break;
     }
     case 343:
     {
          currentAlarmText = F("In den Gärten");
          break;
     }
     case 367:
     {
          currentAlarmText = F("Kaiserstrasse");
          break;
     }
     case 377:
     {
          currentAlarmText = F("Karl-Kling-Strasse");
          break;
     }
     case 393:
     {
          currentAlarmText = F("Kirchweg");
          break;
     }
     case 396:
     {
          currentAlarmText = F("Kleebergstrasse");
          break;
     }
     case 418:
     {
          currentAlarmText = F("Langer Strich");
          break;
     }
     case 436:
     {
          currentAlarmText = F("Lindenstrasse");
          break;
     }
     case 535:
     {
          currentAlarmText = F("Rechtenbacher Hohl");
          break;
     }
     case 541:
     {
          currentAlarmText = F("Rheinfelser Strasse");
          break;
     }
     case 562:
     {
          currentAlarmText = F("Rosenweg");
          break;
     }
     case 595:
     {
          currentAlarmText = F("Schwarze Hohl");
          break;
     }
     case 597:
     {
          currentAlarmText = F("Schwimmbadweg");
          break;
     }
     case 607:
     {
          currentAlarmText = F("Sonnenweg");
          break;
     }
     case 612:
     {
          currentAlarmText = F("Sportplatzstrasse");
          break;
     }
     case 620:
     {
          currentAlarmText = F("Steinhohl");
          break;
     }
     case 637:
     {
          currentAlarmText = F("Taunusstrasse");
          break;
     }
     case 670:
     {
          currentAlarmText = F("Vogelsang");
          break;
     }
     case 676:
     {
          currentAlarmText = F("Waldstrasse");
          break;
     }
     case 688:
     {
          currentAlarmText = F("Weingartenstrasse");
          break;
     }
     case 720:
     {
          currentAlarmText = F("Zum Dorfplatz");
          break;
     }
     case 721:
     {
          currentAlarmText = F("Zum Kolbengraben");
          break;
     }
     //Rödgen
     case 27:
     {
          currentAlarmText = F("Am Bergwald");
          break;
     }
     case 39:
     {
          currentAlarmText = F("Am Kirschenberg");
          break;
     }
     case 65:
     {
          currentAlarmText = F("An der Schillerlinde");
          break;
     }
     case 78:
     {
          currentAlarmText = F("Auf dem Freistück");
          break;
     }
     case 95:
     {
          currentAlarmText = F("Bärner Strasse");
          break;
     }
     case 130:
     {
          currentAlarmText = F("Brunnenweg");
          break;
     }
     case 136:
     {
          currentAlarmText = F("Bürgerhausstrasse");
          break;
     }
     case 140:
     {
          currentAlarmText = F("Burgwiesenweg");
          break;
     }
     case 141:
     {
          currentAlarmText = F("Canonstrasse");
          break;
     }
     case 165:
     {
          currentAlarmText = F("Dreieck");
          break;
     }
     case 220:
     {
          currentAlarmText = F("Friedrich-Ebert-Strasse");
          break;
     }
     case 260:
     {
          currentAlarmText = F("Grossen-Busecker Strasse");
          break;
     }
     case 293:
     {
          currentAlarmText = F("Helgenstockstrasse");
          break;
     }
     case 336:
     {
          currentAlarmText = F("Im Hopfengarten");
          break;
     }
     case 341:
     {
          currentAlarmText = F("Im Uderborn");
          break;
     }
     case 347:
     {
          currentAlarmText = F("In der Roos");
          break;
     }
     case 348:
     {
          currentAlarmText = F("Industriestrasse");
          break;
     }
     case 390:
     {
          currentAlarmText = F("Kirchenring");
          break;
     }
     case 417:
     {
          currentAlarmText = F("Lange Ortsstrasse");
          break;
     }
     case 560:
     {
          currentAlarmText = F("Rosengasse");
          break;
     }
     case 565:
     {
          currentAlarmText = F("Ruhbanksweg");
          break;
     }
     case 598:
     {
          currentAlarmText = F("Seewiesenstrasse");
          break;
     }
     case 617:
     {
          currentAlarmText = F("Steinacker");
          break;
     }
     case 629:
     {
          currentAlarmText = F("Struthstrasse");
          break;
     }
     case 651:
     {
          currentAlarmText = F("Troher Strasse");
          break;
     }
     case 657:
     {
          currentAlarmText = F("Udersbergstrasse");
          break;
     }
     case 671:
     {
          currentAlarmText = F("Vor dem Hegwald");
          break;
     }
     case 719:
     {
          currentAlarmText = F("Zum Bahnhof");
          break;
     }
     case 725:
     {
          currentAlarmText = F("Zur Alten Eiche");
          break;
     }
     case 727:
     {
          currentAlarmText = F("Zur Kastanie");
          break;
     }
     //Wieseck
     case 13:
     {
          currentAlarmText = F("Alte Schulstrasse");
          break;
     }
     case 15:
     {
          currentAlarmText = F("Altenburger Strasse");
          break;
     }
     case 16:
     {
          currentAlarmText = F("Alten-Busecker-Strasse");
          break;
     }
     case 30:
     {
          currentAlarmText = F("Am Eichelbaum");
          break;
     }
     case 31:
     {
          currentAlarmText = F("Am Erlenberg");
          break;
     }
     case 37:
     {
          currentAlarmText = F("Am Kaiserberg");
          break;
     }
     case 40:
     {
          currentAlarmText = F("Am Siegborn");
          break;
     }
     case 44:
     {
          currentAlarmText = F("Am Steinkreuz");
          break;
     }
     case 49:
     {
          currentAlarmText = F("Am Urnenfeld");
          break;
     }
     case 50:
     {
          currentAlarmText = F("Am Wallborn");
          break;
     }
     case 56:
     {
          currentAlarmText = F("An dem Trieb");
          break;
     }
     case 79:
     {
          currentAlarmText = F("Auf dem Kaisersberg");
          break;
     }
     case 80:
     {
          currentAlarmText = F("Auf dem Krohplatz");
          break;
     }
     case 84:
     {
          currentAlarmText = F("August-Bramm-Weg");
          break;
     }
     case 89:
     {
          currentAlarmText = F("Backhausstrasse");
          break;
     }
     case 90:
     {
          currentAlarmText = F("Badenburg Blockstelle");
          break;
     }
     case 91:
     {
          currentAlarmText = F("Badenburger Hohl");
          break;
     }
     case 129:
     {
          currentAlarmText = F("Brunnengasse");
          break;
     }
     case 135:
     {
          currentAlarmText = F("Burgenring");
          break;
     }
     case 145:
     {
          currentAlarmText = F("Carl-Ulrich-Strasse");
          break;
     }
     case 147:
     {
          currentAlarmText = F("Chamissoweg");
          break;
     }
     case 159:
     {
          currentAlarmText = F("Der Lustgarten");
          break;
     }
     case 160:
     {
          currentAlarmText = F("Diebweg");
          break;
     }
     case 167:
     {
          currentAlarmText = F("Dünsbergring");
          break;
     }
     case 172:
     {
          currentAlarmText = F("Ecke");
          break;
     }
     case 176:
     {
          currentAlarmText = F("Eduard-David-Strasse");
          break;
     }
     case 180:
     {
          currentAlarmText = F("Eichenröder Weg");
          break;
     }
     case 183:
     {
          currentAlarmText = F("Eichgasse");
          break;
     }
     case 184:
     {
          currentAlarmText = F("Eisenacher Strasse");
          break;
     }
     case 185:
     {
          currentAlarmText = F("Eisenstein");
          break;
     }
     case 189:
     {
          currentAlarmText = F("Erfurter Strasse");
          break;
     }
     case 191:
     {
          currentAlarmText = F("Ermelgasse");
          break;
     }
     case 231:
     {
          currentAlarmText = F("Gänsmühle");
          break;
     }
     case 234:
     {
          currentAlarmText = F("Gellertweg");
          break;
     }
     case 241:
     {
          currentAlarmText = F("Geraer Strasse");
          break;
     }
     case 244:
     {
          currentAlarmText = F("Giessener Strasse");
          break;
     }
     case 248:
     {
          currentAlarmText = F("Gleibergring");
          break;
     }
     case 251:
     {
          currentAlarmText = F("Gothaer Strasse");
          break;
     }
     case 254:
     {
          currentAlarmText = F("Grabenstrasse");
          break;
     }
     case 257:
     {
          currentAlarmText = F("Greizer Strasse");
          break;
     }
     case 267:
     {
          currentAlarmText = F("Gustav-Stresemann-Ring");
          break;
     }
     case 270:
     {
          currentAlarmText = F("Hagstrasse");
          break;
     }
     case 273:
     {
          currentAlarmText = F("Hangelsteinring");
          break;
     }
     case 274:
     {
          currentAlarmText = F("Hangelsteinstrasse");
          break;
     }
     case 290:
     {
          currentAlarmText = F("Heinrich-Ritzel-Strasse");
          break;
     }
     case 315:
     {
          currentAlarmText = F("Hohensteinring");
          break;
     }
     case 316:
     {
          currentAlarmText = F("Höhenweg");
          break;
     }
     case 320:
     {
          currentAlarmText = F("Hölderlinweg");
          break;
     }
     case 337:
     {
          currentAlarmText = F("Im Kaisersgrund");
          break;
     }
     case 342:
     {
          currentAlarmText = F("In den Erlen");
          break;
     }
     case 344:
     {
          currentAlarmText = F("In der Hunsbach");
          break;
     }
     case 349:
     {
          currentAlarmText = F("Inselweg");
          break;
     }
     case 353:
     {
          currentAlarmText = F("Jenaer Strasse");
          break;
     }
     case 357:
     {
          currentAlarmText = F("Johannesberg");
          break;
     }
     case 364:
     {
          currentAlarmText = F("Jungfernstrasse");
          break;
     }
     case 372:
     {
          currentAlarmText = F("Karl-Benner-Strasse");
          break;
     }
     case 381:
     {
          currentAlarmText = F("Karlstrasse");
          break;
     }
     case 387:
     {
          currentAlarmText = F("Kesslerstrasse");
          break;
     }
     case 388:
     {
          currentAlarmText = F("Kiesweg");
          break;
     }
     case 392:
     {
          currentAlarmText = F("Kirchstrasse");
          break;
     }
     case 402:
     {
          currentAlarmText = F("Kohlweg");
          break;
     }
     case 405:
     {
          currentAlarmText = F("Kornblumenstrasse");
          break;
     }
     case 410:
     {
          currentAlarmText = F("Krumstück");
          break;
     }
     case 429:
     {
          currentAlarmText = F("Lichtenauer Weg");
          break;
     }
     /*case 442:
     {
          currentAlarmText = F("Ludwig-Richter-Strasse");
          break;
     }
     case 450:
     {
          currentAlarmText = F("Marburger Strasse");
          break;
     }*/
     case 462:
     {
          currentAlarmText = F("Martha-Mendel-Weg");
          break;
     }
     case 468:
     {
          currentAlarmText = F("Meininger Weg");
          break;
     }
     case 470:
     {
          currentAlarmText = F("Meissingerweg");
          break;
     }
     case 481:
     {
          currentAlarmText = F("Möserstrasse");
          break;
     }
     case 483:
     {
          currentAlarmText = F("Mühläckerring");
          break;
     }
     case 484:
     {
          currentAlarmText = F("Mühlhäuser Strasse");
          break;
     }
     case 491:
     {
          currentAlarmText = F("Neue Strasse");
          break;
     }
     case 496:
     {
          currentAlarmText = F("Niederfeldstrasse");
          break;
     }
     case 499:
     {
          currentAlarmText = F("Nordhäuser Weg");
          break;
     }
     case 503:
     {
          currentAlarmText = F("Obergarten");
          break;
     }
     case 505:
     {
          currentAlarmText = F("Oberlachweg");
          break;
     }
     case 507:
     {
          currentAlarmText = F("Ockerweg");
          break;
     }
     case 521:
     {
          currentAlarmText = F("Philipp-Scheidemann-Strasse");
          break;
     }
     case 522:
     {
          currentAlarmText = F("Philosophenstrasse");
          break;
     }
     case 530:
     {
          currentAlarmText = F("Rabenauer Strasse");
          break;
     }
     case 537:
     {
          currentAlarmText = F("Reichelsberg");
          break;
     }
     case 540:
     {
          currentAlarmText = F("Reinhard-Strecker-Weg");
          break;
     }
     case 569:
     {
          currentAlarmText = F("Sandacker");
          break;
     }
     case 584:
     {
          currentAlarmText = F("Schmalkaldener Weg");
          break;
     }
     case 586:
     {
          currentAlarmText = F("Schöne Aussicht");
          break;
     }
     case 591:
     {
          currentAlarmText = F("Schustergasse");
          break;
     }
     case 599:
     {
          currentAlarmText = F("Sellnberg");
          break;
     }
     case 615:
     {
          currentAlarmText = F("Staufenbergring");
          break;
     }
     case 619:
     {
          currentAlarmText = F("Steinerne Brücke");
          break;
     }
     case 625:
     {
          currentAlarmText = F("Stiegel");
          break;
     }
     case 627:
     {
          currentAlarmText = F("Struppmühle");
          break;
     }
     case 628:
     {
          currentAlarmText = F("Struppmühlenweg");
          break;
     }
     case 638:
     {
          currentAlarmText = F("Teichweg");
          break;
     }
     case 647:
     {
          currentAlarmText = F("Treiser Weg");
          break;
     }
     case 654:
     {
          currentAlarmText = F("Turnstrasse");
          break;
     }
     case 665:
     {
          currentAlarmText = F("Ursulum");
          break;
     }
     case 668:
     {
          currentAlarmText = F("Vetzbergring");
          break;
     }
     case 669:
     {
          currentAlarmText = F("Vixröder Strasse");
          break;
     }
     case 675:
     {
          currentAlarmText = F("Waldfrieden");
          break;
     }
     case 684:
     {
          currentAlarmText = F("Weidigstrasse");
          break;
     }
     case 687:
     {
          currentAlarmText = F("Weimarer Strasse");
          break;
     }
     case 691:
     {
          currentAlarmText = F("Wellersburgring");
          break;
     }
     case 692:
     {
          currentAlarmText = F("Wellerscheid");
          break;
     }
     case 697:
     {
          currentAlarmText = F("Wettenbergring");
          break;
     }
     case 705:
     {
          currentAlarmText = F("Wilhelm-Liebknecht-Strasse");
          break;
     }
     case 710:
     {
          currentAlarmText = F("Winckelmannstrasse");
          break;
     }
     case 711:
     {
          currentAlarmText = F("Wingert");
          break;
     }
     }
     return currentAlarmText;
}

String getAlarmSubText(unsigned int currentSub)
{
     String currentAlarmText = "";
     switch (currentSub)
     {
     case 1:
     {
          currentAlarmText = F("Baum oder Gegenstand auf der Straße");
          break;
     }
     case 2:
     {
          currentAlarmText = F("Baum umgestürzt");
          break;
     }
     case 3:
     {
          currentAlarmText = F("Bauunfall");
          break;
     }
     case 4:
     {
          currentAlarmText = F("Befreiung von Schneelasten");
          break;
     }
     case 7:
     {
          currentAlarmText = F("Bus des ÖPNV");
          break;
     }
     case 8:
     {
          currentAlarmText = F("Busses ohne Personen");
          break;
     }
     case 9:
     {
          currentAlarmText = F("Containerschiff");
          break;
     }
     case 10:
     {
          currentAlarmText = F("Feld");
          break;
     }
     case 11:
     {
          currentAlarmText = F("Frachtschiff");
          break;
     }
     case 12:
     {
          currentAlarmText = F("einzelner Gasflaschen");
          break;
     }
     case 13:
     {
          currentAlarmText = F("Gaskesselwagens");
          break;
     }
     case 14:
     {
          currentAlarmText = F("einer Gasleitung");
          break;
     }
     case 15:
     {
          currentAlarmText = F("Gastanks");
          break;
     }
     case 16:
     {
          currentAlarmText = F("Gastankfahrzeugs");
          break;
     }
     case 17:
     {
          currentAlarmText = F("Gerümpel im Freien");
          break;
     }
     case 18:
     {
          currentAlarmText = F("Gewerbebetrieb");
          break;
     }
     case 19:
     {
          currentAlarmText = F("Großflugzeug");
          break;
     }
     case 21:
     {
          currentAlarmText = F("Güterzugs");
          break;
     }
     case 22:
     {
          currentAlarmText = F("Heißluftballons");
          break;
     }
     case 23:
     {
          currentAlarmText = F("Hochhaus");
          break;
     }
     case 24:
     {
          currentAlarmText = F("Hubschrauber");
          break;
     }
     case 25:
     {
          currentAlarmText = F("Kfz-Werkstatt");
          break;
     }
     case 26:
     {
          currentAlarmText = F("Kleinflugzeug");
          break;
     }
     case 27:
     {
          currentAlarmText = F("landwirtschaftliche Arbeitsmaschine");
          break;
     }
     case 28:
     {
          currentAlarmText = F("LKW");
          break;
     }
     case 29:
     {
          currentAlarmText = F("Militärmaschine");
          break;
     }
     case 30:
     {
          currentAlarmText = F("Mülltonne");
          break;
     }
     case 31:
     {
          currentAlarmText = F("Pension");
          break;
     }
     case 32:
     {
          currentAlarmText = F("Personen- oder Fahrzeugfähre");
          break;
     }
     case 33:
     {
          currentAlarmText = F("Personenschiffes");
          break;
     }
     case 34:
     {
          currentAlarmText = F("Personenzug");
          break;
     }
     case 35:
     {
          currentAlarmText = F("PKW");
          break;
     }
     case 36:
     {
          currentAlarmText = F("Produktions- und/oder Lagergebäude");
          break;
     }
     case 38:
     {
          currentAlarmText = F("Reisebus");
          break;
     }
     case 39:
     {
          currentAlarmText = F("Schienenfahrzeugs");
          break;
     }
     case 40:
     {
          currentAlarmText = F("Schreinerei");
          break;
     }
     case 41:
     {
          currentAlarmText = F("Schulbus");
          break;
     }
     case 42:
     {
          currentAlarmText = F("Segelboots");
          break;
     }
     case 43:
     {
          currentAlarmText = F("Segelflieger / Paraglider");
          break;
     }
     case 45:
     {
          currentAlarmText = F("Sportboots");
          break;
     }
     case 46:
     {
          currentAlarmText = F("Sportmaschine");
          break;
     }
     case 47:
     {
          currentAlarmText = F("Tankschiff");
          break;
     }
     case 48:
     {
          currentAlarmText = F("Triebfahrzeugs");
          break;
     }
     case 49:
     {
          currentAlarmText = F("U- / S-Bahn-Zug");
          break;
     }
     case 50:
     {
          currentAlarmText = F("Waggon");
          break;
     }
     case 51:
     {
          currentAlarmText = F("Wald");
          break;
     }
     case 52:
     {
          currentAlarmText = F("Wiese");
          break;
     }
     case 53:
     {
          currentAlarmText = F("Windenergieanlage");
          break;
     }
     case 54:
     {
          currentAlarmText = F("Yacht");
          break;
     }
     case 56:
     {
          currentAlarmText = F("Dach abgedeckt/eingestürzt");
          break;
     }
     case 57:
     {
          currentAlarmText = F("Dachstuhlbrand");
          break;
     }
     case 58:
     {
          currentAlarmText = F("Fahrzeug umgestürzt");
          break;
     }
     case 59:
     {
          currentAlarmText = F("Gasgeruch");
          break;
     }
     case 60:
     {
          currentAlarmText = F("Gebäudeeinsturz");
          break;
     }
     case 61:
     {
          currentAlarmText = F("gelöschtes Feuer");
          break;
     }
     case 62:
     {
          currentAlarmText = F("Gerüsteinsturz");
          break;
     }
     case 65:
     {
          currentAlarmText = F("Kaminbrand");
          break;
     }
     case 66:
     {
          currentAlarmText = F("Kellerbrand");
          break;
     }
     case 67:
     {
          currentAlarmText = F("Kfz steckt im Wasser fest");
          break;
     }
     case 68:
     {
          currentAlarmText = F("Kleine Mengen Betriebsstoffe aufnehmen");
          break;
     }
     case 69:
     {
          currentAlarmText = F("Kollision eines Zuges mit einem Straßenfahrzeug");
          break;
     }
     case 70:
     {
          currentAlarmText = F("Kollision zweier Züge");
          break;
     }
     case 71:
     {
          currentAlarmText = F("Kran umgestürzt");
          break;
     }
     case 76:
     {
          currentAlarmText = F("Nachschau");
          break;
     }
     case 82:
     {
          currentAlarmText = F("Notfall-Türöffnung");
          break;
     }
     case 83:
     {
          currentAlarmText = F("Öl auf Bach");
          break;
     }
     case 84:
     {
          currentAlarmText = F("Öl auf Fluss");
          break;
     }
     case 85:
     {
          currentAlarmText = F("Öl auf Hafenbereich");
          break;
     }
     case 86:
     {
          currentAlarmText = F("Öl auf See");
          break;
     }
     case 87:
     {
          currentAlarmText = F("Ölspur");
          break;
     }
     case 88:
     {
          currentAlarmText = F("Person droht zu springen");
          break;
     }
     case 90:
     {
          currentAlarmText = F("Person in Absturzgefahr");
          break;
     }
     case 91:
     {
          currentAlarmText = F("Person im Aufzug");
          break;
     }
     case 92:
     {
          currentAlarmText = F("Person in Bach");
          break;
     }
     case 93:
     {
          currentAlarmText = F("Person in Fluss");
          break;
     }
     case 94:
     {
          currentAlarmText = F("Person in Hafenbereich");
          break;
     }
     case 95:
     {
          currentAlarmText = F("Person in See");
          break;
     }
     case 96:
     {
          currentAlarmText = F("Person unter Zug / U- / S-Bahn / Straßenbahn");
          break;
     }
     case 97:
     {
          currentAlarmText = F("Person verschüttet");
          break;
     }
     case 99:
     {
          currentAlarmText = F("Rauchentwicklung");
          break;
     }
     case 100:
     {
          currentAlarmText = F("Schäden durch umhergewehte Gegenstände");
          break;
     }
     case 101:
     {
          currentAlarmText = F("Sicherung von Gebäudeteilen und Gegenständen");
          break;
     }
     case 102:
     {
          currentAlarmText = F("Straße überflutet");
          break;
     }
     case 104:
     {
          currentAlarmText = F("Tier in Not oder Unfall mit Tier");
          break;
     }
     case 105:
     {
          currentAlarmText = F("Tragehilfe für den Rettungsdienst");
          break;
     }
     case 106:
     {
          currentAlarmText = F("Tür- und Fenstersicherung");
          break;
     }
     case 107:
     {
          currentAlarmText = F("Unfall eines Zuges / einer U- / S-Bahn / Straßenbahn");
          break;
     }
     case 108:
     {
          currentAlarmText = F("Unfall in großen elektrischen Anlagen / Hochspannungsanlagen");
          break;
     }
     case 109:
     {
          currentAlarmText = F("Unfall mit Einsturz von beteiligten Objekten");
          break;
     }
     case 112:
     {
          currentAlarmText = F("Unfall mit radioaktiven Stoffen");
          break;
     }
     case 114:
     {
          currentAlarmText = F("Wasser im Keller, in Tiefgaragen und Unterführungen");
          break;
     }
     case 115:
     {
          currentAlarmText = F("Wasser im Keller");
          break;
     }
     case 116:
     {
          currentAlarmText = F("Wasserrohrbruch");
          break;
     }
     case 117:
     {
          currentAlarmText = F("Wohnungsbrand");
          break;
     }
     case 118:
     {
          currentAlarmText = F("Zimmerbrand");
          break;
     }
     }
     return currentAlarmText;
}

String getAlarmTypeText(unsigned int currentType)
{
     String currentAlarmText = "";
     switch (currentType)
     {
     case 101:
     {
          currentAlarmText = F("F 1");
          break;
     }
     case 102:
     {
          currentAlarmText = F("F 2");
          break;
     }
     case 103:
     {
          currentAlarmText = F("F 2 Y");
          break;
     }
     case 104:
     {
          currentAlarmText = F("F 3");
          break;
     }
     case 105:
     {
          currentAlarmText = F("F 3 Y");
          break;
     }
     case 106:
     {
          currentAlarmText = F("F 4");
          break;
     }
     case 107:
     {
          currentAlarmText = F("F BMA");
          break;
     }
     case 108:
     {
          currentAlarmText = F("F BUS Y");
          break;
     }
     case 109:
     {
          currentAlarmText = F("F FLUG 1 Y");
          break;
     }
     case 110:
     {
          currentAlarmText = F("F FLUG 2 Y");
          break;
     }
     case 111:
     {
          currentAlarmText = F("F GAS 1");
          break;
     }
     case 112:
     {
          currentAlarmText = F("F GAS 2");
          break;
     }
     case 113:
     {
          currentAlarmText = F("F LKW");
          break;
     }
     case 114:
     {
          currentAlarmText = F("F ZUG");
          break;
     }
     case 115:
     {
          currentAlarmText = F("F ZUG Y");
          break;
     }
     case 116:
     {
          currentAlarmText = F("F RWM");
          break;
     }
     case 117:
     {
          currentAlarmText = F("F SCHIFF 1");
          break;
     }
     case 118:
     {
          currentAlarmText = F("F SCHIFF 2");
          break;
     }
     case 119:
     {
          currentAlarmText = F("F SCHIFF 2 Y");
          break;
     }
     case 120:
     {
          currentAlarmText = F("F SCHIFF 2 GEFAHR");
          break;
     }
     case 121:
     {
          currentAlarmText = F("F WALD 1");
          break;
     }
     case 122:
     {
          currentAlarmText = F("F WALD 2");
          break;
     }
     case 201:
     {
          currentAlarmText = F("H 1");
          break;
     }
     case 202:
     {
          currentAlarmText = F("H 1 Y");
          break;
     }
     case 203:
     {
          currentAlarmText = F("H 2");
          break;
     }
     case 204:
     {
          currentAlarmText = F("H ABST Y");
          break;
     }
     case 205:
     {
          currentAlarmText = F("H ELEK");
          break;
     }
     case 206:
     {
          currentAlarmText = F("H EINST Y");
          break;
     }
     case 207:
     {
          currentAlarmText = F("H FLUSS");
          break;
     }
     case 208:
     {
          currentAlarmText = F("H FLUSS Y");
          break;
     }
     case 209:
     {
          currentAlarmText = F("H WASS Y");
          break;
     }
     case 210:
     {
          currentAlarmText = F("H GAS 1");
          break;
     }
     case 211:
     {
          currentAlarmText = F("H GAS 2");
          break;
     }
     case 212:
     {
          currentAlarmText = F("H GEFAHR 1");
          break;
     }
     case 213:
     {
          currentAlarmText = F("H GEFAHR 2");
          break;
     }
     case 214:
     {
          currentAlarmText = F("H KLEMM 1 Y");
          break;
     }
     case 215:
     {
          currentAlarmText = F("H KLEMM 2 Y");
          break;
     }
     case 216:
     {
          currentAlarmText = F("H ÖL FLUSS");
          break;
     }
     case 217:
     {
          currentAlarmText = F("H ÖL WASS");
          break;
     }
     case 218:
     {
          currentAlarmText = F("H RADIOAKTIV");
          break;
     }
     case 219:
     {
          currentAlarmText = F("H SCHIFF");
          break;
     }
     case 220:
     {
          currentAlarmText = F("H SCHIFF Y");
          break;
     }
     case 221:
     {
          currentAlarmText = F("H ZUG 1 Y");
          break;
     }
     case 222:
     {
          currentAlarmText = F("H ZUG 2 Y");
          break;
     }
     case 301:
     {
          currentAlarmText = F("U UNWETTER STURM");
          break;
     }
     case 302:
     {
          currentAlarmText = F("U UNWETTER WASSER");
          break;
     }
     case 401:
     {
          currentAlarmText = F("K");
          break;
     }
     case 402:
     {
          currentAlarmText = F("R 0 K");
          break;
     }
     case 403:
     {
          currentAlarmText = F("R 0");
          break;
     }
     case 404:
     {
          currentAlarmText = F("R 1");
          break;
     }
     case 405:
     {
          currentAlarmText = F("R 2");
          break;
     }
     case 406:
     {
          currentAlarmText = F("R 3");
          break;
     }
     case 407:
     {
          currentAlarmText = F("R LEBEL");
          break;
     }
     case 408:
     {
          currentAlarmText = F("R MANV");
          break;
     }
     case 501:
     {
          currentAlarmText = F("THW"); // THW Technischer Zug
          break;
     }
     case 502:
     {
          currentAlarmText = F("THW SEG"); // THW Spezialeinsatzgruppe
          break;
     }
     case 503:
     {
          currentAlarmText = F("THW FB"); // THW Fachberatung
          break;
     }
     case 504:
     {
          currentAlarmText = F("THW BEL"); // THW Fachgruppe Beleuchtung
          break;
     }
     case 505:
     {
          currentAlarmText = F("THW BRB"); // THW Fachgruppe Brückenbau
          break;
     }
     case 506:
     {
          currentAlarmText = F("THW E"); // THW Fachgruppe Elektroversorgung
          break;
     }
     case 507:
     {
          currentAlarmText = F("THW FK"); // THW Fachgruppe Führung und Kommunikation
          break;
     }
     case 508:
     {
          currentAlarmText = F("THW WV"); // THW Fachgruppe Weitverkehrstrupp
          break;
     }
     case 509:
     {
          currentAlarmText = F("THW HÖRG"); // THW Fachgruppe Höhenrettung
          break;
     }
     case 510:
     {
          currentAlarmText = F("THW I"); // THW Fachgruppe Infrastruktur
          break;
     }
     case 511:
     {
          currentAlarmText = F("THW LOG V"); // THW Fachgruppe Logistik, Versorgungstrupp
          break;
     }
     case 512:
     {
          currentAlarmText = F("THW LOG M"); // THW Fachgruppe Logistik, Materialerhaltungstrupp
          break;
     }
     case 513:
     {
          currentAlarmText = F("THW ORT"); // THW Fachgruppe Ortung
          break;
     }
     case 514:
     {
          currentAlarmText = F("THW ÖL"); // THW Fachgruppe Ölwehr
          break;
     }
     case 515:
     {
          currentAlarmText = F("THW R"); // THW Fachgruppe Räumen
          break;
     }
     case 516:
     {
          currentAlarmText = F("THW TW"); // THW Fachgruppe Trinkwasserversorgung
          break;
     }
     case 517:
     {
          currentAlarmText = F("THW SPR"); // THW Fachgruppe Sprengen
          break;
     }
     case 518:
     {
          currentAlarmText = F("THW WASSER"); // THW Fachgruppe Wassergefahren
          break;
     }
     case 519:
     {
          currentAlarmText = F("THW WP"); // THW Fachgruppe Wasserschaden, Pumpen
          break;
     }
     case 520:
     {
          currentAlarmText = F("THW EGS"); // THW Technischer Zug mit Einsatzgerüstsystem
          break;
     }
     case 521:
     {
          currentAlarmText = F("THW ASH"); // THW Technischer Zug mit Abstützsystem-Holz
          break;
     }

     case 601:
     {
          currentAlarmText = F("P BR"); // Polizei Bereitstellung
          break;
     }
     case 602:
     {
          currentAlarmText = F("P BOMBE"); // Polizei Bombendrohung
          break;
     }
     case 603:
     {
          currentAlarmText = F("P USBV"); // Polizei USBV-Fund
          break;
     }
     case 604:
     {
          currentAlarmText = F("P GEISEL"); // Polizei Geisellage
          break;
     }
     case 605:
     {
          currentAlarmText = F("P SEK"); // Polizei SEK Einsatz
          break;
     }
     case 606:
     {
          currentAlarmText = F("P LEBEL"); // Polizei Lebensbedrohliche Lage
          break;
     }
     case 1:
     {
          currentAlarmText = F("FME Test");
          break;
     }
     default:
     {
          currentAlarmText = F("UNKLAR");
          break;
     }
     }
     return currentAlarmText;
}

String getAlarmCategoryText(unsigned int currentType)
{
     String currentAlarmText = "";
     if (currentType >= 101 && currentType <= 199)
     {
          currentAlarmText = "Feuer";
     }
     else if (currentType >= 201 && currentType <= 299)
     {
          currentAlarmText = "Technische Hilfeleistung";
     }
     else if (currentType >= 301 && currentType <= 399)
     {
          currentAlarmText = "Unwetter";
     }
     else if (currentType >= 401 && currentType <= 499)
     {
          currentAlarmText = "Rettungsdienst";
     }
     else if (currentType >= 501 && currentType <= 599)
     {
          currentAlarmText = "THW";
     }
     else if (currentType >= 601 && currentType <= 699)
     {
          currentAlarmText = "Polizei";
     }
     else
     {
          currentAlarmText = F("UNKLAR");
     }
     return currentAlarmText;
}

int getAlarmCategory(unsigned int currentType)
{
     int currentAlarmText = 0;
     if (currentType >= 101 && currentType <= 199)
     {
          currentAlarmText = 1;
     }
     else if (currentType >= 201 && currentType <= 299)
     {
          currentAlarmText = 2;
     }
     else if (currentType >= 301 && currentType <= 399)
     {
          currentAlarmText = 3;
     }
     else if (currentType >= 401 && currentType <= 499)
     {
          currentAlarmText = 4;
     }
     else if (currentType >= 501 && currentType <= 599)
     {
          currentAlarmText = 5;
     }
     else if (currentType >= 601 && currentType <= 699)
     {
          currentAlarmText = 6;
     }
     else
     {
     }
     return currentAlarmText;
}

String getCombinedAdress(int plz, int city, int street, int number, String addition)
{
  return getAlarmStreetText(street) + " " + String(number) + addition + ", " + getAlarmPLZText(plz) + " " + getAlarmCityText(city);
}

void resetAlarm()
{
  save_type = 0;
  save_sub = 0;
  save_plz = 0;
  save_city = 0;
  save_street = 0;
  save_number = 0;
  save_addition = "";
  save_adress = "";
  save_comment = "";
  save_nodeIdString = "";
}

void saveAlarm(int type, int sub, int plz, int city, int street, int number, String addition, String adress, String comment, String nodeIdString)
{
  save_type = type;
  save_sub = sub;
  save_plz = plz;
  save_city = city;
  save_street = street;
  save_number = number;
  save_addition = addition;
  if (adress.isEmpty())
  {
    adress = getCombinedAdress(plz, city, street, number, addition);
  }
  save_adress = adress;
  save_comment = comment;
  save_nodeIdString = nodeIdString;
  writeAlarm();
  resetAlarm();
}

void cleanCurrentAlarm()
{
  alarm_plz = 0;
  alarm_city = 0;
  alarm_street = 0;
  alarm_number = 0;
  alarm_addition = "";
}