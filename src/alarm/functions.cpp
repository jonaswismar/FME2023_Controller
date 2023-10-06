#include <Arduino.h>

#include "filesystem\functions.h"

#include "variables.h"

String getAlarmPLZText(unsigned int currentPLZ)
{
	String returnValue = "";
	switch (currentPLZ)
	{
	case 1:
	{
		returnValue = F("35305");
		break;
	}
	case 2:
	{
		returnValue = F("35321");
		break;
	}
	case 3:
	{
		returnValue = F("35390");
		break;
	}
	case 4:
	{
		returnValue = F("35392");
		break;
	}
	case 5:
	{
		returnValue = F("35394");
		break;
	}
	case 6:
	{
		returnValue = F("35396");
		break;
	}
	case 7:
	{
		returnValue = F("35398");
		break;
	}
	case 8:
	{
		returnValue = F("35410");
		break;
	}
	case 9:
	{
		returnValue = F("35415");
		break;
	}
	case 10:
	{
		returnValue = F("35418");
		break;
	}
	case 11:
	{
		returnValue = F("35423");
		break;
	}
	case 12:
	{
		returnValue = F("35428");
		break;
	}
	case 13:
	{
		returnValue = F("35435");
		break;
	}
	case 14:
	{
		returnValue = F("35440");
		break;
	}
	case 15:
	{
		returnValue = F("35444");
		break;
	}
	case 16:
	{
		returnValue = F("35447");
		break;
	}
	case 17:
	{
		returnValue = F("35452");
		break;
	}
	case 18:
	{
		returnValue = F("35457");
		break;
	}
	case 19:
	{
		returnValue = F("35460");
		break;
	}
	case 20:
	{
		returnValue = F("35463");
		break;
	}
	case 21:
	{
		returnValue = F("35466");
		break;
	}
	case 22:
	{
		returnValue = F("35469");
		break;
	}
	}
	return returnValue;
}

String getAlarmCityText(unsigned int currentCity)
{
	String returnValue = "";
	switch (currentCity)
	{
	case 1:
	{
		returnValue = F("Albach");
		break;
	}
	case 2:
	{
		returnValue = F("Allendorf");
		break;
	}
	case 3:
	{
		returnValue = F("Allendorf (Lumda)");
		break;
	}
	case 4:
	{
		returnValue = F("Allertshausen");
		break;
	}
	case 5:
	{
		returnValue = F("Alten-Buseck");
		break;
	}
	case 6:
	{
		returnValue = F("Altenhain");
		break;
	}
	case 7:
	{
		returnValue = F("Annerod");
		break;
	}
	case 8:
	{
		returnValue = F("Bellersheim");
		break;
	}
	case 9:
	{
		returnValue = F("Beltershain");
		break;
	}
	case 10:
	{
		returnValue = F("Bersrod");
		break;
	}
	case 11:
	{
		returnValue = F("Bettenhausen");
		break;
	}
	case 12:
	{
		returnValue = F("Beuern");
		break;
	}
	case 13:
	{
		returnValue = F("Biebertal");
		break;
	}
	case 14:
	{
		returnValue = F("Birklar");
		break;
	}
	case 15:
	{
		returnValue = F("Burkhardsfelden");
		break;
	}
	case 16:
	{
		returnValue = F("Buseck");
		break;
	}
	case 17:
	{
		returnValue = F("Cleeberg");
		break;
	}
	case 18:
	{
		returnValue = F("Climbach");
		break;
	}
	case 19:
	{
		returnValue = F("Daubringen");
		break;
	}
	case 20:
	{
		returnValue = F("Dorf-Güll");
		break;
	}
	case 21:
	{
		returnValue = F("Dornholzhausen");
		break;
	}
	case 22:
	{
		returnValue = F("Eberstadt");
		break;
	}
	case 23:
	{
		returnValue = F("Espa");
		break;
	}
	case 24:
	{
		returnValue = F("Ettingshausen");
		break;
	}
	case 25:
	{
		returnValue = F("Fellingshausen");
		break;
	}
	case 26:
	{
		returnValue = F("Fernwald");
		break;
	}
	case 27:
	{
		returnValue = F("Frankenbach");
		break;
	}
	case 28:
	{
		returnValue = F("Freienseen");
		break;
	}
	case 29:
	{
		returnValue = F("Garbenteich");
		break;
	}
	case 30:
	{
		returnValue = F("Geilshausen");
		break;
	}
	case 31:
	{
		returnValue = F("Gießen");
		break;
	}
	case 32:
	{
		returnValue = F("Göbelnrod");
		break;
	}
	case 33:
	{
		returnValue = F("Gonterskirchen");
		break;
	}
	case 34:
	{
		returnValue = F("Großen-Buseck");
		break;
	}
	case 35:
	{
		returnValue = F("Großen-Linden");
		break;
	}
	case 36:
	{
		returnValue = F("Grünberg");
		break;
	}
	case 37:
	{
		returnValue = F("Grüningen");
		break;
	}
	case 38:
	{
		returnValue = F("Harbach");
		break;
	}
	case 39:
	{
		returnValue = F("Hattenrod");
		break;
	}
	case 40:
	{
		returnValue = F("Hausen");
		break;
	}
	case 41:
	{
		returnValue = F("Heuchelheim");
		break;
	}
	case 42:
	{
		returnValue = F("Heuchelheim an der Lahn");
		break;
	}
	case 43:
	{
		returnValue = F("Holzheim");
		break;
	}
	case 44:
	{
		returnValue = F("Hungen");
		break;
	}
	case 45:
	{
		returnValue = F("Inheiden");
		break;
	}
	case 46:
	{
		returnValue = F("Kesselbach");
		break;
	}
	case 47:
	{
		returnValue = F("Kinzenbach");
		break;
	}
	case 48:
	{
		returnValue = F("Klein-Eichen");
		break;
	}
	case 49:
	{
		returnValue = F("Kleinlinden");
		break;
	}
	case 50:
	{
		returnValue = F("Kloster Arnsburg");
		break;
	}
	case 51:
	{
		returnValue = F("Königsberg");
		break;
	}
	case 52:
	{
		returnValue = F("Krofdorf-Gleiberg");
		break;
	}
	case 53:
	{
		returnValue = F("Krumbach");
		break;
	}
	case 54:
	{
		returnValue = F("Langd");
		break;
	}
	case 55:
	{
		returnValue = F("Langgöns");
		break;
	}
	case 56:
	{
		returnValue = F("Langsdorf");
		break;
	}
	case 57:
	{
		returnValue = F("Lardenbach");
		break;
	}
	case 58:
	{
		returnValue = F("Laubach");
		break;
	}
	case 59:
	{
		returnValue = F("Launsbach");
		break;
	}
	case 60:
	{
		returnValue = F("Lauter");
		break;
	}
	case 61:
	{
		returnValue = F("Lehnheim");
		break;
	}
	case 62:
	{
		returnValue = F("Leihgestern");
		break;
	}
	case 63:
	{
		returnValue = F("Lich");
		break;
	}
	case 64:
	{
		returnValue = F("Linden");
		break;
	}
	case 65:
	{
		returnValue = F("Lindenstruth");
		break;
	}
	case 66:
	{
		returnValue = F("Lollar");
		break;
	}
	case 67:
	{
		returnValue = F("Londorf");
		break;
	}
	case 68:
	{
		returnValue = F("Lützellinden");
		break;
	}
	case 69:
	{
		returnValue = F("Lumda");
		break;
	}
	case 70:
	{
		returnValue = F("Mainzlar");
		break;
	}
	case 71:
	{
		returnValue = F("Münster");
		break;
	}
	case 72:
	{
		returnValue = F("Muschenheim");
		break;
	}
	case 73:
	{
		returnValue = F("Nieder-Bessingen");
		break;
	}
	case 74:
	{
		returnValue = F("Niederkleen");
		break;
	}
	case 75:
	{
		returnValue = F("Nonnenroth");
		break;
	}
	case 76:
	{
		returnValue = F("Nordeck");
		break;
	}
	case 77:
	{
		returnValue = F("Obbornhofen");
		break;
	}
	case 78:
	{
		returnValue = F("Ober-Bessingen");
		break;
	}
	case 79:
	{
		returnValue = F("Oberkleen");
		break;
	}
	case 80:
	{
		returnValue = F("Odenhausen");
		break;
	}
	case 81:
	{
		returnValue = F("Odenhausen (Lumda)");
		break;
	}
	case 82:
	{
		returnValue = F("Oppenrod");
		break;
	}
	case 83:
	{
		returnValue = F("Pohlheim");
		break;
	}
	case 84:
	{
		returnValue = F("Queckborn");
		break;
	}
	case 85:
	{
		returnValue = F("Rabenau");
		break;
	}
	case 86:
	{
		returnValue = F("Rabertshausen");
		break;
	}
	case 87:
	{
		returnValue = F("Reinhardshain");
		break;
	}
	case 88:
	{
		returnValue = F("Reiskirchen");
		break;
	}
	case 89:
	{
		returnValue = F("Rodheim-Bieber");
		break;
	}
	case 90:
	{
		returnValue = F("Rodheim");
		break;
	}
	case 91:
	{
		returnValue = F("Rödgen");
		break;
	}
	case 92:
	{
		returnValue = F("Röthges");
		break;
	}
	case 93:
	{
		returnValue = F("Rüddingshausen");
		break;
	}
	case 94:
	{
		returnValue = F("Ruppertsburg");
		break;
	}
	case 95:
	{
		returnValue = F("Ruttershausen");
		break;
	}
	case 96:
	{
		returnValue = F("Saasen");
		break;
	}
	case 97:
	{
		returnValue = F("Salzböden");
		break;
	}
	case 98:
	{
		returnValue = F("Seenbrücke");
		break;
	}
	case 99:
	{
		returnValue = F("Stangenrod");
		break;
	}
	case 100:
	{
		returnValue = F("Staufenberg");
		break;
	}
	case 101:
	{
		returnValue = F("Steinbach");
		break;
	}
	case 102:
	{
		returnValue = F("Steinheim");
		break;
	}
	case 103:
	{
		returnValue = F("Stockhausen");
		break;
	}
	case 104:
	{
		returnValue = F("Trais-Horloff");
		break;
	}
	case 105:
	{
		returnValue = F("Treis an der Lumda");
		break;
	}
	case 106:
	{
		returnValue = F("Trohe");
		break;
	}
	case 107:
	{
		returnValue = F("Vetzberg");
		break;
	}
	case 108:
	{
		returnValue = F("Watzenborn-Steinberg");
		break;
	}
	case 109:
	{
		returnValue = F("Weickartshain");
		break;
	}
	case 110:
	{
		returnValue = F("Weitershain");
		break;
	}
	case 111:
	{
		returnValue = F("Wettenberg");
		break;
	}
	case 112:
	{
		returnValue = F("Wetterfeld");
		break;
	}
	case 113:
	{
		returnValue = F("Wieseck");
		break;
	}
	case 114:
	{
		returnValue = F("Winnerod");
		break;
	}
	case 115:
	{
		returnValue = F("Wißmar");
		break;
	}
	}
	return returnValue;
}

String getAlarmStreetText(unsigned int currentStreet)
{
	String returnValue = "";
	switch (currentStreet)
	{
	case 1:
	{
		returnValue = F("A.-Paul-Weber-Straße");
		break;
	}
	case 2:
	{
		returnValue = F("Adalbert-Stifter-Straße");
		break;
	}
	case 3:
	{
		returnValue = F("Adam-Opel-Straße");
		break;
	}
	case 4:
	{
		returnValue = F("Adam-Scheurer-Straße");
		break;
	}
	case 5:
	{
		returnValue = F("Adlerweg");
		break;
	}
	case 6:
	{
		returnValue = F("Admonter Ring");
		break;
	}
	case 7:
	{
		returnValue = F("Adolf-Wieber-Straße");
		break;
	}
	case 8:
	{
		returnValue = F("Adolph-Kolping-Straße");
		break;
	}
	case 9:
	{
		returnValue = F("Ärmelgasse");
		break;
	}
	case 10:
	{
		returnValue = F("Äschersweg");
		break;
	}
	case 11:
	{
		returnValue = F("Aherweg");
		break;
	}
	case 12:
	{
		returnValue = F("Ahornstraße");
		break;
	}
	case 13:
	{
		returnValue = F("Ahornweg");
		break;
	}
	case 14:
	{
		returnValue = F("Akazienweg");
		break;
	}
	case 15:
	{
		returnValue = F("Albacher Hof");
		break;
	}
	case 16:
	{
		returnValue = F("Albacher Straße");
		break;
	}
	case 17:
	{
		returnValue = F("Albacher Weg");
		break;
	}
	case 18:
	{
		returnValue = F("Albert-Bossler-Straße");
		break;
	}
	case 19:
	{
		returnValue = F("Albert-Schmidt-Straße");
		break;
	}
	case 20:
	{
		returnValue = F("Albert-Schweitzer-Straße");
		break;
	}
	case 21:
	{
		returnValue = F("Albrecht-Dürer-Straße");
		break;
	}
	case 22:
	{
		returnValue = F("Alfred-Bock-Straße");
		break;
	}
	case 23:
	{
		returnValue = F("Alfred-Funk-Straße");
		break;
	}
	case 24:
	{
		returnValue = F("Alicenstraße");
		break;
	}
	case 25:
	{
		returnValue = F("Allee");
		break;
	}
	case 26:
	{
		returnValue = F("Allendörfer Au");
		break;
	}
	case 27:
	{
		returnValue = F("Allendorfer Straße");
		break;
	}
	case 28:
	{
		returnValue = F("Allertshäuser Straße");
		break;
	}
	case 29:
	{
		returnValue = F("Alsfelder Straße");
		break;
	}
	case 30:
	{
		returnValue = F("Altarasstraße");
		break;
	}
	case 31:
	{
		returnValue = F("Alte Dorfstraße");
		break;
	}
	case 32:
	{
		returnValue = F("Alte Gasse");
		break;
	}
	case 33:
	{
		returnValue = F("Alte Gerberei");
		break;
	}
	case 34:
	{
		returnValue = F("Alte Gießener Straße");
		break;
	}
	case 35:
	{
		returnValue = F("Alte Heerstraße");
		break;
	}
	case 36:
	{
		returnValue = F("Alte Höhe");
		break;
	}
	case 37:
	{
		returnValue = F("Alte Kirchgönser Straße");
		break;
	}
	case 38:
	{
		returnValue = F("Alte Licher Straße");
		break;
	}
	case 39:
	{
		returnValue = F("Alte Schulhöfe");
		break;
	}
	case 40:
	{
		returnValue = F("Alte Schulstraße");
		break;
	}
	case 41:
	{
		returnValue = F("Alte Straße");
		break;
	}
	case 42:
	{
		returnValue = F("Alte Waldstraße");
		break;
	}
	case 43:
	{
		returnValue = F("Alte Wegscheide");
		break;
	}
	case 44:
	{
		returnValue = F("Alte Weickartshainer Straße");
		break;
	}
	case 45:
	{
		returnValue = F("Alten-Busecker-Straße");
		break;
	}
	case 46:
	{
		returnValue = F("Alten-Busecker Weg");
		break;
	}
	case 47:
	{
		returnValue = F("Alten Busecker Straße");
		break;
	}
	case 48:
	{
		returnValue = F("Alten Busecker Weg");
		break;
	}
	case 49:
	{
		returnValue = F("Altenbergstraße");
		break;
	}
	case 50:
	{
		returnValue = F("Altenbergweg");
		break;
	}
	case 51:
	{
		returnValue = F("Altenburger Straße");
		break;
	}
	case 52:
	{
		returnValue = F("Altenfeldsweg");
		break;
	}
	case 53:
	{
		returnValue = F("Altenhainer Straße");
		break;
	}
	case 54:
	{
		returnValue = F("Alter Bornberg");
		break;
	}
	case 55:
	{
		returnValue = F("Alter Krofdorfer Weg");
		break;
	}
	case 56:
	{
		returnValue = F("Alter Langgönser Weg");
		break;
	}
	case 57:
	{
		returnValue = F("Alter Laubacher Weg");
		break;
	}
	case 58:
	{
		returnValue = F("Alter Rathausplatz");
		break;
	}
	case 59:
	{
		returnValue = F("Alter Steinbacher Weg");
		break;
	}
	case 60:
	{
		returnValue = F("Alter Weg");
		break;
	}
	case 61:
	{
		returnValue = F("Alter Wetzlarer Weg");
		break;
	}
	case 62:
	{
		returnValue = F("Altes Feld");
		break;
	}
	case 63:
	{
		returnValue = F("Altes Gericht");
		break;
	}
	case 64:
	{
		returnValue = F("Altmarkstraße");
		break;
	}
	case 65:
	{
		returnValue = F("Altmühlenweg");
		break;
	}
	case 66:
	{
		returnValue = F("Altvaterstraße");
		break;
	}
	case 67:
	{
		returnValue = F("Altweiher");
		break;
	}
	case 68:
	{
		returnValue = F("Am Abendstern");
		break;
	}
	case 69:
	{
		returnValue = F("Am Ahmeser");
		break;
	}
	case 70:
	{
		returnValue = F("Am Ahorn");
		break;
	}
	case 71:
	{
		returnValue = F("Am Alten Bahnhof");
		break;
	}
	case 72:
	{
		returnValue = F("Am Alten Flughafen");
		break;
	}
	case 73:
	{
		returnValue = F("Am Alten Friedhof");
		break;
	}
	case 74:
	{
		returnValue = F("Am Alten Gaswerk");
		break;
	}
	case 75:
	{
		returnValue = F("Am Alten Hof");
		break;
	}
	case 76:
	{
		returnValue = F("Am Alten Kirchenweg");
		break;
	}
	case 77:
	{
		returnValue = F("Am Alten Loh");
		break;
	}
	case 78:
	{
		returnValue = F("Am Alten Marktplatz");
		break;
	}
	case 79:
	{
		returnValue = F("Am Alten Sportplatz");
		break;
	}
	case 80:
	{
		returnValue = F("Am Alten Steinbruch");
		break;
	}
	case 81:
	{
		returnValue = F("Am Alten Stück");
		break;
	}
	case 82:
	{
		returnValue = F("Am Alten Turm");
		break;
	}
	case 83:
	{
		returnValue = F("Am Altenrod");
		break;
	}
	case 84:
	{
		returnValue = F("Am Atzelpfad");
		break;
	}
	case 85:
	{
		returnValue = F("Am Augarten");
		break;
	}
	case 86:
	{
		returnValue = F("Am Aulenberg");
		break;
	}
	case 87:
	{
		returnValue = F("Am Bach");
		break;
	}
	case 88:
	{
		returnValue = F("Am Backhaus");
		break;
	}
	case 89:
	{
		returnValue = F("Am Bahndamm");
		break;
	}
	case 90:
	{
		returnValue = F("Am Bahnhof");
		break;
	}
	case 91:
	{
		returnValue = F("Am Baumstück");
		break;
	}
	case 92:
	{
		returnValue = F("Am Beerberg");
		break;
	}
	case 93:
	{
		returnValue = F("Am Bellersheimer Fußweg");
		break;
	}
	case 94:
	{
		returnValue = F("Am Berg");
		break;
	}
	case 95:
	{
		returnValue = F("Am Bergwald");
		break;
	}
	case 96:
	{
		returnValue = F("Am Bergwerkswald");
		break;
	}
	case 97:
	{
		returnValue = F("Am Biehl");
		break;
	}
	case 98:
	{
		returnValue = F("Am Bienenstrauch");
		break;
	}
	case 99:
	{
		returnValue = F("Am Biengarten");
		break;
	}
	case 100:
	{
		returnValue = F("Am Bindböhl");
		break;
	}
	case 101:
	{
		returnValue = F("Am Bindling");
		break;
	}
	case 102:
	{
		returnValue = F("Am Birkacker");
		break;
	}
	case 103:
	{
		returnValue = F("Am Birkfeld");
		break;
	}
	case 104:
	{
		returnValue = F("Am Boden");
		break;
	}
	case 105:
	{
		returnValue = F("Am Born");
		break;
	}
	case 106:
	{
		returnValue = F("Am Bornberg");
		break;
	}
	case 107:
	{
		returnValue = F("Am Bornweg");
		break;
	}
	case 108:
	{
		returnValue = F("Am Boxacker");
		break;
	}
	case 109:
	{
		returnValue = F("Am Boxberg");
		break;
	}
	case 110:
	{
		returnValue = F("Am Breiten Stein");
		break;
	}
	case 111:
	{
		returnValue = F("Am Brennofen");
		break;
	}
	case 112:
	{
		returnValue = F("Am Breuerbergsweiher");
		break;
	}
	case 113:
	{
		returnValue = F("Am Brückenberg");
		break;
	}
	case 114:
	{
		returnValue = F("Am Brückmann");
		break;
	}
	case 115:
	{
		returnValue = F("Am Buchacker");
		break;
	}
	case 116:
	{
		returnValue = F("Am Buchenberg");
		break;
	}
	case 117:
	{
		returnValue = F("Am Budwichen");
		break;
	}
	case 118:
	{
		returnValue = F("Am Bürgelgrund");
		break;
	}
	case 119:
	{
		returnValue = F("Am Bürgerhaus");
		break;
	}
	case 120:
	{
		returnValue = F("Am Busch");
		break;
	}
	case 121:
	{
		returnValue = F("Am Damm");
		break;
	}
	case 122:
	{
		returnValue = F("Am Dietert");
		break;
	}
	case 123:
	{
		returnValue = F("Am Döngesberg");
		break;
	}
	case 124:
	{
		returnValue = F("Am Dorfgemeinschaftshaus");
		break;
	}
	case 125:
	{
		returnValue = F("Am Dorftriesch");
		break;
	}
	case 126:
	{
		returnValue = F("Am Dorfzentrum");
		break;
	}
	case 127:
	{
		returnValue = F("Am Dornacker");
		break;
	}
	case 128:
	{
		returnValue = F("Am Dornbusch");
		break;
	}
	case 129:
	{
		returnValue = F("Am Dreschplatz");
		break;
	}
	case 130:
	{
		returnValue = F("Am Drosselschlag");
		break;
	}
	case 131:
	{
		returnValue = F("Am Dünsberg");
		break;
	}
	case 132:
	{
		returnValue = F("Am Eckartsrot");
		break;
	}
	case 133:
	{
		returnValue = F("Am Edelgarten");
		break;
	}
	case 134:
	{
		returnValue = F("Am Eichberg");
		break;
	}
	case 135:
	{
		returnValue = F("Am Eichelbaum");
		break;
	}
	case 136:
	{
		returnValue = F("Am Eichwiesenfeld");
		break;
	}
	case 137:
	{
		returnValue = F("Am Eisenberg");
		break;
	}
	case 138:
	{
		returnValue = F("Am Elisabethenpfad");
		break;
	}
	case 139:
	{
		returnValue = F("Am Erlen");
		break;
	}
	case 140:
	{
		returnValue = F("Am Erlenberg");
		break;
	}
	case 141:
	{
		returnValue = F("Am Erlenhof");
		break;
	}
	case 142:
	{
		returnValue = F("Am Eselspfad");
		break;
	}
	case 143:
	{
		returnValue = F("Am Färbgraben");
		break;
	}
	case 144:
	{
		returnValue = F("Am Falltor");
		break;
	}
	case 145:
	{
		returnValue = F("Am Faltergarten");
		break;
	}
	case 146:
	{
		returnValue = F("Am Fauerbacher Rain");
		break;
	}
	case 147:
	{
		returnValue = F("Am Festplatz");
		break;
	}
	case 148:
	{
		returnValue = F("Am Flachsbach");
		break;
	}
	case 149:
	{
		returnValue = F("Am Fliederbusch");
		break;
	}
	case 150:
	{
		returnValue = F("Am Forsthaus");
		break;
	}
	case 151:
	{
		returnValue = F("Am Fortberg");
		break;
	}
	case 152:
	{
		returnValue = F("Am Freien Koben");
		break;
	}
	case 153:
	{
		returnValue = F("Am Friedhof");
		break;
	}
	case 154:
	{
		returnValue = F("Am Froschloch");
		break;
	}
	case 155:
	{
		returnValue = F("Am Frühzaun");
		break;
	}
	case 156:
	{
		returnValue = F("Am Gänsberg");
		break;
	}
	case 157:
	{
		returnValue = F("Am Galgenberg");
		break;
	}
	case 158:
	{
		returnValue = F("Am Gallichten");
		break;
	}
	case 159:
	{
		returnValue = F("Am Gansacker");
		break;
	}
	case 160:
	{
		returnValue = F("Am Garten");
		break;
	}
	case 161:
	{
		returnValue = F("Am Geiersberg");
		break;
	}
	case 162:
	{
		returnValue = F("Am Gemeindewald");
		break;
	}
	case 163:
	{
		returnValue = F("Am Gewenn");
		break;
	}
	case 164:
	{
		returnValue = F("Am Gewerbepark");
		break;
	}
	case 165:
	{
		returnValue = F("Am Giebel");
		break;
	}
	case 166:
	{
		returnValue = F("Am Ginsterbusch");
		break;
	}
	case 167:
	{
		returnValue = F("Am Glocklappen");
		break;
	}
	case 168:
	{
		returnValue = F("Am Graben");
		break;
	}
	case 169:
	{
		returnValue = F("Am Gräbchen");
		break;
	}
	case 170:
	{
		returnValue = F("Am Grassee");
		break;
	}
	case 171:
	{
		returnValue = F("Am Grasweg");
		break;
	}
	case 172:
	{
		returnValue = F("Am Grenzwall");
		break;
	}
	case 173:
	{
		returnValue = F("Am Grillplatz");
		break;
	}
	case 174:
	{
		returnValue = F("Am Großacker");
		break;
	}
	case 175:
	{
		returnValue = F("Am Gründchen");
		break;
	}
	case 176:
	{
		returnValue = F("Am Grünen Grund");
		break;
	}
	case 177:
	{
		returnValue = F("Am Güterbahnhof");
		break;
	}
	case 178:
	{
		returnValue = F("Am Haanes");
		break;
	}
	case 179:
	{
		returnValue = F("Am Hahngarten");
		break;
	}
	case 180:
	{
		returnValue = F("Am Hain");
		break;
	}
	case 181:
	{
		returnValue = F("Am Hainberg");
		break;
	}
	case 182:
	{
		returnValue = F("Am Haingraben");
		break;
	}
	case 183:
	{
		returnValue = F("Am Hainkopf");
		break;
	}
	case 184:
	{
		returnValue = F("Am Hainstrauch");
		break;
	}
	case 185:
	{
		returnValue = F("Am Hammelstein");
		break;
	}
	case 186:
	{
		returnValue = F("Am Hang");
		break;
	}
	case 187:
	{
		returnValue = F("Am Hardtberg");
		break;
	}
	case 188:
	{
		returnValue = F("Am Hasengarten");
		break;
	}
	case 189:
	{
		returnValue = F("Am Hassel");
		break;
	}
	case 190:
	{
		returnValue = F("Am Heddrich");
		break;
	}
	case 191:
	{
		returnValue = F("Am Heegersgraben");
		break;
	}
	case 192:
	{
		returnValue = F("Am Heiligenstock");
		break;
	}
	case 193:
	{
		returnValue = F("Am Heimatmuseum");
		break;
	}
	case 194:
	{
		returnValue = F("Am Helgenstock");
		break;
	}
	case 195:
	{
		returnValue = F("Am Hellenberg");
		break;
	}
	case 196:
	{
		returnValue = F("Am Hellerpfad");
		break;
	}
	case 197:
	{
		returnValue = F("Am Hellerrain");
		break;
	}
	case 198:
	{
		returnValue = F("Am Herzgarten");
		break;
	}
	case 199:
	{
		returnValue = F("Am Hesselberg");
		break;
	}
	case 200:
	{
		returnValue = F("Am Hetzberg");
		break;
	}
	case 201:
	{
		returnValue = F("Am Hinterhof");
		break;
	}
	case 202:
	{
		returnValue = F("Am Hirtenweg");
		break;
	}
	case 203:
	{
		returnValue = F("Am Hirtsgarten");
		break;
	}
	case 204:
	{
		returnValue = F("Am Hochbehälter");
		break;
	}
	case 205:
	{
		returnValue = F("Am Hofgut");
		break;
	}
	case 206:
	{
		returnValue = F("Am Hohberg");
		break;
	}
	case 207:
	{
		returnValue = F("Am Hollerbusch");
		break;
	}
	case 208:
	{
		returnValue = F("Am Holzapfelbaum");
		break;
	}
	case 209:
	{
		returnValue = F("Am Hombiegel");
		break;
	}
	case 210:
	{
		returnValue = F("Am Hügel");
		break;
	}
	case 211:
	{
		returnValue = F("Am Hundsbrunnen");
		break;
	}
	case 212:
	{
		returnValue = F("Am Hutsberg");
		break;
	}
	case 213:
	{
		returnValue = F("Am Jagdstock");
		break;
	}
	case 214:
	{
		returnValue = F("Am Kahlsberg");
		break;
	}
	case 215:
	{
		returnValue = F("Am Kahnplätzchen");
		break;
	}
	case 216:
	{
		returnValue = F("Am Kaiserberg");
		break;
	}
	case 217:
	{
		returnValue = F("Am Kalkbruch");
		break;
	}
	case 218:
	{
		returnValue = F("Am Kammerpfad");
		break;
	}
	case 219:
	{
		returnValue = F("Am Kasimir");
		break;
	}
	case 220:
	{
		returnValue = F("Am Kellerberg");
		break;
	}
	case 221:
	{
		returnValue = F("Am Kesselberg");
		break;
	}
	case 222:
	{
		returnValue = F("Am Keßlersgarten");
		break;
	}
	case 223:
	{
		returnValue = F("Am Kies");
		break;
	}
	case 224:
	{
		returnValue = F("Am Kinnwald");
		break;
	}
	case 225:
	{
		returnValue = F("Am Kirchberg");
		break;
	}
	case 226:
	{
		returnValue = F("Am Kirchgarten");
		break;
	}
	case 227:
	{
		returnValue = F("Am Kirchhofsgarten");
		break;
	}
	case 228:
	{
		returnValue = F("Am Kirschenberg");
		break;
	}
	case 229:
	{
		returnValue = F("Am Kirschenwald");
		break;
	}
	case 230:
	{
		returnValue = F("Am Kleinen Graben");
		break;
	}
	case 231:
	{
		returnValue = F("Am Kleinfeldchen");
		break;
	}
	case 232:
	{
		returnValue = F("Am Knappensee");
		break;
	}
	case 233:
	{
		returnValue = F("Am Knottenberg");
		break;
	}
	case 234:
	{
		returnValue = F("Am Köpfel");
		break;
	}
	case 235:
	{
		returnValue = F("Am Köstgraben");
		break;
	}
	case 236:
	{
		returnValue = F("Am Kohlacker");
		break;
	}
	case 237:
	{
		returnValue = F("Am Kohlgraben");
		break;
	}
	case 238:
	{
		returnValue = F("Am Kratzenberg");
		break;
	}
	case 239:
	{
		returnValue = F("Am Kreuzacker");
		break;
	}
	case 240:
	{
		returnValue = F("Am Kreuzboden");
		break;
	}
	case 241:
	{
		returnValue = F("Am Kreuzweg");
		break;
	}
	case 242:
	{
		returnValue = F("Am Lärchenwald");
		break;
	}
	case 243:
	{
		returnValue = F("Am Läusköppel");
		break;
	}
	case 244:
	{
		returnValue = F("Am Larbach");
		break;
	}
	case 245:
	{
		returnValue = F("Am Launscheid");
		break;
	}
	case 246:
	{
		returnValue = F("Am Lehnköppel");
		break;
	}
	case 247:
	{
		returnValue = F("Am Lemberg");
		break;
	}
	case 248:
	{
		returnValue = F("Am Leuchtfaß");
		break;
	}
	case 249:
	{
		returnValue = F("Am Liehgen");
		break;
	}
	case 250:
	{
		returnValue = F("Am Lindenbaum");
		break;
	}
	case 251:
	{
		returnValue = F("Am Lindenberg");
		break;
	}
	case 252:
	{
		returnValue = F("Am Linnacker");
		break;
	}
	case 253:
	{
		returnValue = F("Am Lochacker");
		break;
	}
	case 254:
	{
		returnValue = F("Am Lohacker");
		break;
	}
	case 255:
	{
		returnValue = F("Am Lohberg");
		break;
	}
	case 256:
	{
		returnValue = F("Am Lückebach");
		break;
	}
	case 257:
	{
		returnValue = F("Am Lückenbach");
		break;
	}
	case 258:
	{
		returnValue = F("Am Lückenberg");
		break;
	}
	case 259:
	{
		returnValue = F("Am Lutherberg");
		break;
	}
	case 260:
	{
		returnValue = F("Am Mandlerwasen");
		break;
	}
	case 261:
	{
		returnValue = F("Am Margretengraben");
		break;
	}
	case 262:
	{
		returnValue = F("Am Mühlacker");
		break;
	}
	case 263:
	{
		returnValue = F("Am Mühlberg");
		break;
	}
	case 264:
	{
		returnValue = F("Am Mühlchen");
		break;
	}
	case 265:
	{
		returnValue = F("Am Mühlgraben");
		break;
	}
	case 266:
	{
		returnValue = F("Am Mühlwald");
		break;
	}
	case 267:
	{
		returnValue = F("Am Neuen Friedhof");
		break;
	}
	case 268:
	{
		returnValue = F("Am Nordend");
		break;
	}
	case 269:
	{
		returnValue = F("Am Nußbaum");
		break;
	}
	case 270:
	{
		returnValue = F("Am Obergarten");
		break;
	}
	case 271:
	{
		returnValue = F("Am Oberholz");
		break;
	}
	case 272:
	{
		returnValue = F("Am Obertor");
		break;
	}
	case 273:
	{
		returnValue = F("Am Oberweg");
		break;
	}
	case 274:
	{
		returnValue = F("Am Park");
		break;
	}
	case 275:
	{
		returnValue = F("Am Pfad");
		break;
	}
	case 276:
	{
		returnValue = F("Am Pfaffenstrauch");
		break;
	}
	case 277:
	{
		returnValue = F("Am Pfahlgraben");
		break;
	}
	case 278:
	{
		returnValue = F("Am Pfalzrain");
		break;
	}
	case 279:
	{
		returnValue = F("Am Pfarrgarten");
		break;
	}
	case 280:
	{
		returnValue = F("Am Plättchen");
		break;
	}
	case 281:
	{
		returnValue = F("Am Plattenberg");
		break;
	}
	case 282:
	{
		returnValue = F("Am Preßberg");
		break;
	}
	case 283:
	{
		returnValue = F("Am Priemengrund");
		break;
	}
	case 284:
	{
		returnValue = F("Am Rabels");
		break;
	}
	case 285:
	{
		returnValue = F("Am Rain");
		break;
	}
	case 286:
	{
		returnValue = F("Am Rainacker");
		break;
	}
	case 287:
	{
		returnValue = F("Am Ramsberg");
		break;
	}
	case 288:
	{
		returnValue = F("Am Rieden");
		break;
	}
	case 289:
	{
		returnValue = F("Am Riethenberg");
		break;
	}
	case 290:
	{
		returnValue = F("Am Rillscheid");
		break;
	}
	case 291:
	{
		returnValue = F("Am Ringgraben");
		break;
	}
	case 292:
	{
		returnValue = F("Am Rinnerborn");
		break;
	}
	case 293:
	{
		returnValue = F("Am Rödegraben");
		break;
	}
	case 294:
	{
		returnValue = F("Am Rommel");
		break;
	}
	case 295:
	{
		returnValue = F("Am Rondell");
		break;
	}
	case 296:
	{
		returnValue = F("Am Rosenberg");
		break;
	}
	case 297:
	{
		returnValue = F("Am Rotacker");
		break;
	}
	case 298:
	{
		returnValue = F("Am Ruhestein");
		break;
	}
	case 299:
	{
		returnValue = F("Am Sänges");
		break;
	}
	case 300:
	{
		returnValue = F("Am Schäferling");
		break;
	}
	case 301:
	{
		returnValue = F("Am Schafbach");
		break;
	}
	case 302:
	{
		returnValue = F("Am Schafhof");
		break;
	}
	case 303:
	{
		returnValue = F("Am Schafstall");
		break;
	}
	case 304:
	{
		returnValue = F("Am Schautanz");
		break;
	}
	case 305:
	{
		returnValue = F("Am Scheid");
		break;
	}
	case 306:
	{
		returnValue = F("Am Schellenberg");
		break;
	}
	case 307:
	{
		returnValue = F("Am Schießloh");
		break;
	}
	case 308:
	{
		returnValue = F("Am Schießrain");
		break;
	}
	case 309:
	{
		returnValue = F("Am Schiffenweg");
		break;
	}
	case 310:
	{
		returnValue = F("Am Schindwasen");
		break;
	}
	case 311:
	{
		returnValue = F("Am Schliffgarten");
		break;
	}
	case 312:
	{
		returnValue = F("Am Schlossgarten");
		break;
	}
	case 313:
	{
		returnValue = F("Am Schlosspark");
		break;
	}
	case 314:
	{
		returnValue = F("Am Schloßpark");
		break;
	}
	case 315:
	{
		returnValue = F("Am Schlund");
		break;
	}
	case 316:
	{
		returnValue = F("Am Schottengarten");
		break;
	}
	case 317:
	{
		returnValue = F("Am Schwanensee");
		break;
	}
	case 318:
	{
		returnValue = F("Am Schwimmbad");
		break;
	}
	case 319:
	{
		returnValue = F("Am Seechen");
		break;
	}
	case 320:
	{
		returnValue = F("Am Seeköppel");
		break;
	}
	case 321:
	{
		returnValue = F("Am Siegborn");
		break;
	}
	case 322:
	{
		returnValue = F("Am Sieghaus");
		break;
	}
	case 323:
	{
		returnValue = F("Am Silbach");
		break;
	}
	case 324:
	{
		returnValue = F("Am Silberloch");
		break;
	}
	case 325:
	{
		returnValue = F("Am Sonnenberg");
		break;
	}
	case 326:
	{
		returnValue = F("Am Sonnenhang");
		break;
	}
	case 327:
	{
		returnValue = F("Am Sportfeld");
		break;
	}
	case 328:
	{
		returnValue = F("Am Sportplatz");
		break;
	}
	case 329:
	{
		returnValue = F("Am Stater");
		break;
	}
	case 330:
	{
		returnValue = F("Am Steckelchen");
		break;
	}
	case 331:
	{
		returnValue = F("Am Steg");
		break;
	}
	case 332:
	{
		returnValue = F("Am Stein");
		break;
	}
	case 333:
	{
		returnValue = F("Am Steinacker");
		break;
	}
	case 334:
	{
		returnValue = F("Am Steinberg");
		break;
	}
	case 335:
	{
		returnValue = F("Am Steinbruch");
		break;
	}
	case 336:
	{
		returnValue = F("Am Steinern Kreuz");
		break;
	}
	case 337:
	{
		returnValue = F("Am Steinernen Kreuz");
		break;
	}
	case 338:
	{
		returnValue = F("Am Steinernweg");
		break;
	}
	case 339:
	{
		returnValue = F("Am Steinköppel");
		break;
	}
	case 340:
	{
		returnValue = F("Am Steinkreuz");
		break;
	}
	case 341:
	{
		returnValue = F("Am Steinnörrn");
		break;
	}
	case 342:
	{
		returnValue = F("Am Steinrück");
		break;
	}
	case 343:
	{
		returnValue = F("Am Stelzenberg");
		break;
	}
	case 344:
	{
		returnValue = F("Am Stock");
		break;
	}
	case 345:
	{
		returnValue = F("Am Stockacker");
		break;
	}
	case 346:
	{
		returnValue = F("Am Stockhaus");
		break;
	}
	case 347:
	{
		returnValue = F("Am Strauch");
		break;
	}
	case 348:
	{
		returnValue = F("Am Streitkopf");
		break;
	}
	case 349:
	{
		returnValue = F("Am Stück");
		break;
	}
	case 350:
	{
		returnValue = F("Am Stümpfenweg");
		break;
	}
	case 351:
	{
		returnValue = F("Am Südhang");
		break;
	}
	case 352:
	{
		returnValue = F("Am Tagbau");
		break;
	}
	case 353:
	{
		returnValue = F("Am Tann");
		break;
	}
	case 354:
	{
		returnValue = F("Am Tannenberg");
		break;
	}
	case 355:
	{
		returnValue = F("Am Tannenkopf");
		break;
	}
	case 356:
	{
		returnValue = F("Am Tannenwäldchen");
		break;
	}
	case 357:
	{
		returnValue = F("Am Throms Garten");
		break;
	}
	case 358:
	{
		returnValue = F("Am Tiefen Graben");
		break;
	}
	case 359:
	{
		returnValue = F("Am Trieb");
		break;
	}
	case 360:
	{
		returnValue = F("Am Triesch");
		break;
	}
	case 361:
	{
		returnValue = F("Am Trisch");
		break;
	}
	case 362:
	{
		returnValue = F("Am Turnerplatz");
		break;
	}
	case 363:
	{
		returnValue = F("Am Unteren Rain");
		break;
	}
	case 364:
	{
		returnValue = F("Am Urnenfeld");
		break;
	}
	case 365:
	{
		returnValue = F("Am Veilchenhang");
		break;
	}
	case 366:
	{
		returnValue = F("Am Vogelsang");
		break;
	}
	case 367:
	{
		returnValue = F("Am Vogteigericht");
		break;
	}
	case 368:
	{
		returnValue = F("Am Vorderen Tor");
		break;
	}
	case 369:
	{
		returnValue = F("Am Wäldchen");
		break;
	}
	case 370:
	{
		returnValue = F("Am Wässerling");
		break;
	}
	case 371:
	{
		returnValue = F("Am Wald");
		break;
	}
	case 372:
	{
		returnValue = F("Am Waldweg");
		break;
	}
	case 373:
	{
		returnValue = F("Am Wall");
		break;
	}
	case 374:
	{
		returnValue = F("Am Wallborn");
		break;
	}
	case 375:
	{
		returnValue = F("Am Wallgraben");
		break;
	}
	case 376:
	{
		returnValue = F("Am Wartturm");
		break;
	}
	case 377:
	{
		returnValue = F("Am Wartweg");
		break;
	}
	case 378:
	{
		returnValue = F("Am Wasserfall");
		break;
	}
	case 379:
	{
		returnValue = F("Am Wasserhaus");
		break;
	}
	case 380:
	{
		returnValue = F("Am Wasserturm");
		break;
	}
	case 381:
	{
		returnValue = F("Am Wehrgraben");
		break;
	}
	case 382:
	{
		returnValue = F("Am Weidacker");
		break;
	}
	case 383:
	{
		returnValue = F("Am Weidenborn");
		break;
	}
	case 384:
	{
		returnValue = F("Am Weiher");
		break;
	}
	case 385:
	{
		returnValue = F("Am Weihergarten");
		break;
	}
	case 386:
	{
		returnValue = F("Am Weimer");
		break;
	}
	case 387:
	{
		returnValue = F("Am Weinberg");
		break;
	}
	case 388:
	{
		returnValue = F("Am Weingarten");
		break;
	}
	case 389:
	{
		returnValue = F("Am Wiesengrund");
		break;
	}
	case 390:
	{
		returnValue = F("Am Wieslappen");
		break;
	}
	case 391:
	{
		returnValue = F("Am Wildgarten");
		break;
	}
	case 392:
	{
		returnValue = F("Am Wingert");
		break;
	}
	case 393:
	{
		returnValue = F("Am Winkelsborn");
		break;
	}
	case 394:
	{
		returnValue = F("Am Wolfsgraben");
		break;
	}
	case 395:
	{
		returnValue = F("Am Wüsten Placken");
		break;
	}
	case 396:
	{
		returnValue = F("Am Zehntfrei");
		break;
	}
	case 397:
	{
		returnValue = F("Am Ziegenberg");
		break;
	}
	case 398:
	{
		returnValue = F("Am Ziegenköppel");
		break;
	}
	case 399:
	{
		returnValue = F("Am Zimmerplatz");
		break;
	}
	case 400:
	{
		returnValue = F("Am Zolch");
		break;
	}
	case 401:
	{
		returnValue = F("Am Zollstock");
		break;
	}
	case 402:
	{
		returnValue = F("Am Zwenger");
		break;
	}
	case 403:
	{
		returnValue = F("Am alten Sportplatz");
		break;
	}
	case 404:
	{
		returnValue = F("Am großen Köppel");
		break;
	}
	case 405:
	{
		returnValue = F("Am grünen Herrenweg");
		break;
	}
	case 406:
	{
		returnValue = F("Am kleinen Riedweg");
		break;
	}
	case 407:
	{
		returnValue = F("Am weißen Driesch");
		break;
	}
	case 408:
	{
		returnValue = F("Am weißen Stein");
		break;
	}
	case 409:
	{
		returnValue = F("Ammerweg");
		break;
	}
	case 410:
	{
		returnValue = F("Amselweg");
		break;
	}
	case 411:
	{
		returnValue = F("Amthausstraße");
		break;
	}
	case 412:
	{
		returnValue = F("Amtsgerichtsstraße");
		break;
	}
	case 413:
	{
		returnValue = F("An Steins Garten");
		break;
	}
	case 414:
	{
		returnValue = F("An dem Doberg");
		break;
	}
	case 415:
	{
		returnValue = F("An dem Trieb");
		break;
	}
	case 416:
	{
		returnValue = F("An den Berggärten");
		break;
	}
	case 417:
	{
		returnValue = F("An den Birken");
		break;
	}
	case 418:
	{
		returnValue = F("An den Gärten");
		break;
	}
	case 419:
	{
		returnValue = F("An den Hafergärten");
		break;
	}
	case 420:
	{
		returnValue = F("An den Holleräckern");
		break;
	}
	case 421:
	{
		returnValue = F("An den Schulgärten");
		break;
	}
	case 422:
	{
		returnValue = F("An den Steinäckern");
		break;
	}
	case 423:
	{
		returnValue = F("An den Teichen");
		break;
	}
	case 424:
	{
		returnValue = F("An der Alten Bach");
		break;
	}
	case 425:
	{
		returnValue = F("An der Alten Lahn");
		break;
	}
	case 426:
	{
		returnValue = F("An der Alten Post");
		break;
	}
	case 427:
	{
		returnValue = F("An der Amtmannsmühle");
		break;
	}
	case 428:
	{
		returnValue = F("An der Automeile");
		break;
	}
	case 429:
	{
		returnValue = F("An der Bahn");
		break;
	}
	case 430:
	{
		returnValue = F("An der Beune");
		break;
	}
	case 431:
	{
		returnValue = F("An der Bleiche");
		break;
	}
	case 432:
	{
		returnValue = F("An der Breitwiese");
		break;
	}
	case 433:
	{
		returnValue = F("An der Eiche");
		break;
	}
	case 434:
	{
		returnValue = F("An der Fels");
		break;
	}
	case 435:
	{
		returnValue = F("An der Großheck");
		break;
	}
	case 436:
	{
		returnValue = F("An der Halde");
		break;
	}
	case 437:
	{
		returnValue = F("An der Hardt");
		break;
	}
	case 438:
	{
		returnValue = F("An der Haselhecke");
		break;
	}
	case 439:
	{
		returnValue = F("An der Hell");
		break;
	}
	case 440:
	{
		returnValue = F("An der Hessenhalle");
		break;
	}
	case 441:
	{
		returnValue = F("An der Hohen Furche");
		break;
	}
	case 442:
	{
		returnValue = F("An der Hohl");
		break;
	}
	case 443:
	{
		returnValue = F("An der Horloff");
		break;
	}
	case 444:
	{
		returnValue = F("An der Johanneskirche");
		break;
	}
	case 445:
	{
		returnValue = F("An der Kaserne");
		break;
	}
	case 446:
	{
		returnValue = F("An der Kirche");
		break;
	}
	case 447:
	{
		returnValue = F("An der Kläranlage");
		break;
	}
	case 448:
	{
		returnValue = F("An der Kloppmaschin");
		break;
	}
	case 449:
	{
		returnValue = F("An der Koppe");
		break;
	}
	case 450:
	{
		returnValue = F("An der Lauter");
		break;
	}
	case 451:
	{
		returnValue = F("An der Liebigshöhe");
		break;
	}
	case 452:
	{
		returnValue = F("An der Lohmühle");
		break;
	}
	case 453:
	{
		returnValue = F("An der Mittelhohl");
		break;
	}
	case 454:
	{
		returnValue = F("An der Mooseburg");
		break;
	}
	case 455:
	{
		returnValue = F("An der Mühle");
		break;
	}
	case 456:
	{
		returnValue = F("An der Neuen Schule");
		break;
	}
	case 457:
	{
		returnValue = F("An der Ochsenweide");
		break;
	}
	case 458:
	{
		returnValue = F("An der Pfarrwiese");
		break;
	}
	case 459:
	{
		returnValue = F("An der Pforte");
		break;
	}
	case 460:
	{
		returnValue = F("An der Ringelshöhe");
		break;
	}
	case 461:
	{
		returnValue = F("An der Roten Mühle");
		break;
	}
	case 462:
	{
		returnValue = F("An der Schillerlinde");
		break;
	}
	case 463:
	{
		returnValue = F("An der Schoberschneise");
		break;
	}
	case 464:
	{
		returnValue = F("An der Schule");
		break;
	}
	case 465:
	{
		returnValue = F("An der Seemühle");
		break;
	}
	case 466:
	{
		returnValue = F("An der Stadtkirche");
		break;
	}
	case 467:
	{
		returnValue = F("An der Steinrütsche");
		break;
	}
	case 468:
	{
		returnValue = F("An der Straße nach Freienseen");
		break;
	}
	case 469:
	{
		returnValue = F("An der Stühl");
		break;
	}
	case 470:
	{
		returnValue = F("An der Unterpforte");
		break;
	}
	case 471:
	{
		returnValue = F("An der Vogelhütte");
		break;
	}
	case 472:
	{
		returnValue = F("An der Volkshalle");
		break;
	}
	case 473:
	{
		returnValue = F("An der Waldscheuer");
		break;
	}
	case 474:
	{
		returnValue = F("An der Waldschule");
		break;
	}
	case 475:
	{
		returnValue = F("An der Wann");
		break;
	}
	case 476:
	{
		returnValue = F("An der Wasserdelle");
		break;
	}
	case 477:
	{
		returnValue = F("An der Wetter");
		break;
	}
	case 478:
	{
		returnValue = F("An der Wieseck");
		break;
	}
	case 479:
	{
		returnValue = F("An der Zaunburg");
		break;
	}
	case 480:
	{
		returnValue = F("An der Ziegelei");
		break;
	}
	case 481:
	{
		returnValue = F("An der Ziegelhütte");
		break;
	}
	case 482:
	{
		returnValue = F("Andreas-Breidert-Straße");
		break;
	}
	case 483:
	{
		returnValue = F("Andreasteich");
		break;
	}
	case 484:
	{
		returnValue = F("Andree Allee");
		break;
	}
	case 485:
	{
		returnValue = F("Anger");
		break;
	}
	case 486:
	{
		returnValue = F("Angerweg");
		break;
	}
	case 487:
	{
		returnValue = F("Anna-Mettbach-Straße");
		break;
	}
	case 488:
	{
		returnValue = F("Anne-Frank-Straße");
		break;
	}
	case 489:
	{
		returnValue = F("Anneröder Straße");
		break;
	}
	case 490:
	{
		returnValue = F("Anneröder Weg");
		break;
	}
	case 491:
	{
		returnValue = F("Annette-Kolb-Weg");
		break;
	}
	case 492:
	{
		returnValue = F("Anton-Schlecker-Straße");
		break;
	}
	case 493:
	{
		returnValue = F("Appelstraße");
		break;
	}
	case 494:
	{
		returnValue = F("Appenbörner Straße");
		break;
	}
	case 495:
	{
		returnValue = F("Appenborner Weg");
		break;
	}
	case 496:
	{
		returnValue = F("Arndtstraße");
		break;
	}
	case 497:
	{
		returnValue = F("Arnsburger Straße");
		break;
	}
	case 498:
	{
		returnValue = F("Arnsburger Weg");
		break;
	}
	case 499:
	{
		returnValue = F("Aspengasse");
		break;
	}
	case 500:
	{
		returnValue = F("Asternstraße");
		break;
	}
	case 501:
	{
		returnValue = F("Asternweg");
		break;
	}
	case 502:
	{
		returnValue = F("Asterweg");
		break;
	}
	case 503:
	{
		returnValue = F("Astrid-Lindgren-Straße");
		break;
	}
	case 504:
	{
		returnValue = F("Atzbacher Straße");
		break;
	}
	case 505:
	{
		returnValue = F("Atzenhainer Straße");
		break;
	}
	case 506:
	{
		returnValue = F("Aubach");
		break;
	}
	case 507:
	{
		returnValue = F("Aubernweg");
		break;
	}
	case 508:
	{
		returnValue = F("Auf dem Berg");
		break;
	}
	case 509:
	{
		returnValue = F("Auf dem Brühl");
		break;
	}
	case 510:
	{
		returnValue = F("Auf dem Falkenberg");
		break;
	}
	case 511:
	{
		returnValue = F("Auf dem Freistück");
		break;
	}
	case 512:
	{
		returnValue = F("Auf dem Geiersberg");
		break;
	}
	case 513:
	{
		returnValue = F("Auf dem Göbler");
		break;
	}
	case 514:
	{
		returnValue = F("Auf dem Hofdriesch");
		break;
	}
	case 515:
	{
		returnValue = F("Auf dem Hüttenberg");
		break;
	}
	case 516:
	{
		returnValue = F("Auf dem Kaisersberg");
		break;
	}
	case 517:
	{
		returnValue = F("Auf dem Klinkgraben");
		break;
	}
	case 518:
	{
		returnValue = F("Auf dem Köppel");
		break;
	}
	case 519:
	{
		returnValue = F("Auf dem Kranzenberg");
		break;
	}
	case 520:
	{
		returnValue = F("Auf dem Krohplatz");
		break;
	}
	case 521:
	{
		returnValue = F("Auf dem Langen Furt");
		break;
	}
	case 522:
	{
		returnValue = F("Auf dem Luh");
		break;
	}
	case 523:
	{
		returnValue = F("Auf dem Melmes");
		break;
	}
	case 524:
	{
		returnValue = F("Auf dem Mühlberg");
		break;
	}
	case 525:
	{
		returnValue = F("Auf dem Pfannstiel");
		break;
	}
	case 526:
	{
		returnValue = F("Auf dem Schind");
		break;
	}
	case 527:
	{
		returnValue = F("Auf dem Stein");
		break;
	}
	case 528:
	{
		returnValue = F("Auf dem Steinkopf");
		break;
	}
	case 529:
	{
		returnValue = F("Auf dem Stiel");
		break;
	}
	case 530:
	{
		returnValue = F("Auf dem Trieb");
		break;
	}
	case 531:
	{
		returnValue = F("Auf dem Weinberg");
		break;
	}
	case 532:
	{
		returnValue = F("Auf den Röden");
		break;
	}
	case 533:
	{
		returnValue = F("Auf der Bach");
		break;
	}
	case 534:
	{
		returnValue = F("Auf der Berglach");
		break;
	}
	case 535:
	{
		returnValue = F("Auf der Beun");
		break;
	}
	case 536:
	{
		returnValue = F("Auf der Beunde");
		break;
	}
	case 537:
	{
		returnValue = F("Auf der Bleiche");
		break;
	}
	case 538:
	{
		returnValue = F("Auf der Böhl");
		break;
	}
	case 539:
	{
		returnValue = F("Auf der Dreispitz");
		break;
	}
	case 540:
	{
		returnValue = F("Auf der Guckerte");
		break;
	}
	case 541:
	{
		returnValue = F("Auf der Hege");
		break;
	}
	case 542:
	{
		returnValue = F("Auf der Heide");
		break;
	}
	case 543:
	{
		returnValue = F("Auf der Höh");
		break;
	}
	case 544:
	{
		returnValue = F("Auf der Höll");
		break;
	}
	case 545:
	{
		returnValue = F("Auf der Hohl");
		break;
	}
	case 546:
	{
		returnValue = F("Auf der Landwehr");
		break;
	}
	case 547:
	{
		returnValue = F("Auf der Laye");
		break;
	}
	case 548:
	{
		returnValue = F("Auf der Leimenkaute");
		break;
	}
	case 549:
	{
		returnValue = F("Auf der Linde");
		break;
	}
	case 550:
	{
		returnValue = F("Auf der Planke");
		break;
	}
	case 551:
	{
		returnValue = F("Auf der Platt");
		break;
	}
	case 552:
	{
		returnValue = F("Auf der Platte");
		break;
	}
	case 553:
	{
		returnValue = F("Auf der Queckbörner Höhe");
		break;
	}
	case 554:
	{
		returnValue = F("Auf der Rute");
		break;
	}
	case 555:
	{
		returnValue = F("Auf der Schanze");
		break;
	}
	case 556:
	{
		returnValue = F("Auf der Wann");
		break;
	}
	case 557:
	{
		returnValue = F("Auf der Weide");
		break;
	}
	case 558:
	{
		returnValue = F("Auf der Weißburg");
		break;
	}
	case 559:
	{
		returnValue = F("Auf der Windhecke");
		break;
	}
	case 560:
	{
		returnValue = F("August-Balzer-Weg");
		break;
	}
	case 561:
	{
		returnValue = F("August-Bramm-Weg");
		break;
	}
	case 562:
	{
		returnValue = F("August-Hermann-Francke-Weg");
		break;
	}
	case 563:
	{
		returnValue = F("August-Krieger-Straße");
		break;
	}
	case 564:
	{
		returnValue = F("August-Messer-Straße");
		break;
	}
	case 565:
	{
		returnValue = F("Auhof");
		break;
	}
	case 566:
	{
		returnValue = F("Aulbachstraße");
		break;
	}
	case 567:
	{
		returnValue = F("Aulweg");
		break;
	}
	case 568:
	{
		returnValue = F("Außenliegend");
		break;
	}
	case 569:
	{
		returnValue = F("Außenliegend Am Heerweg");
		break;
	}
	case 570:
	{
		returnValue = F("Außenliegend Bahnhaus");
		break;
	}
	case 571:
	{
		returnValue = F("Außenliegend Kalksteinwerk");
		break;
	}
	case 572:
	{
		returnValue = F("Außenliegend Windhof");
		break;
	}
	case 573:
	{
		returnValue = F("Ausserhalb");
		break;
	}
	case 574:
	{
		returnValue = F("Außerhalb");
		break;
	}
	case 575:
	{
		returnValue = F("Aussiger Straße");
		break;
	}
	case 576:
	{
		returnValue = F("Austraße");
		break;
	}
	case 577:
	{
		returnValue = F("Autobahnmeisterei");
		break;
	}
	case 578:
	{
		returnValue = F("Autobahnraststätte");
		break;
	}
	case 579:
	{
		returnValue = F("Auweg");
		break;
	}
	case 580:
	{
		returnValue = F("Bachgärten");
		break;
	}
	case 581:
	{
		returnValue = F("Bachgartenstraße");
		break;
	}
	case 582:
	{
		returnValue = F("Bachgasse");
		break;
	}
	case 583:
	{
		returnValue = F("Bachstraße");
		break;
	}
	case 584:
	{
		returnValue = F("Bachweg");
		break;
	}
	case 585:
	{
		returnValue = F("Bachwiesenweg");
		break;
	}
	case 586:
	{
		returnValue = F("Backhausgasse");
		break;
	}
	case 587:
	{
		returnValue = F("Backhausstraße");
		break;
	}
	case 588:
	{
		returnValue = F("Backhausweg");
		break;
	}
	case 589:
	{
		returnValue = F("Badenburg Blockstelle");
		break;
	}
	case 590:
	{
		returnValue = F("Badenburger Hohl");
		break;
	}
	case 591:
	{
		returnValue = F("Badenburger Weg");
		break;
	}
	case 592:
	{
		returnValue = F("Bänningerstraße");
		break;
	}
	case 593:
	{
		returnValue = F("Bärner Straße");
		break;
	}
	case 594:
	{
		returnValue = F("Bahnhaus");
		break;
	}
	case 595:
	{
		returnValue = F("Bahnhofstraße");
		break;
	}
	case 596:
	{
		returnValue = F("Bahnposten");
		break;
	}
	case 597:
	{
		returnValue = F("Bahnstraße");
		break;
	}
	case 598:
	{
		returnValue = F("Banater Weg");
		break;
	}
	case 599:
	{
		returnValue = F("Banngartenstraße");
		break;
	}
	case 600:
	{
		returnValue = F("Banngartenweg");
		break;
	}
	case 601:
	{
		returnValue = F("Bantzerweg");
		break;
	}
	case 602:
	{
		returnValue = F("Barbarossaweg");
		break;
	}
	case 603:
	{
		returnValue = F("Barfüßergasse");
		break;
	}
	case 604:
	{
		returnValue = F("Barresgraben");
		break;
	}
	case 605:
	{
		returnValue = F("Basaltwerk");
		break;
	}
	case 606:
	{
		returnValue = F("Baumgarten");
		break;
	}
	case 607:
	{
		returnValue = F("Baumgartenstraße");
		break;
	}
	case 608:
	{
		returnValue = F("Baumgartenweg");
		break;
	}
	case 609:
	{
		returnValue = F("Baumkircher Straße");
		break;
	}
	case 610:
	{
		returnValue = F("Bauroth");
		break;
	}
	case 611:
	{
		returnValue = F("Bechsteinweg");
		break;
	}
	case 612:
	{
		returnValue = F("Beergartenstraße");
		break;
	}
	case 613:
	{
		returnValue = F("Beethovenstraße");
		break;
	}
	case 614:
	{
		returnValue = F("Begonienweg");
		break;
	}
	case 615:
	{
		returnValue = F("Behringstraße");
		break;
	}
	case 616:
	{
		returnValue = F("Bei den Fahrten");
		break;
	}
	case 617:
	{
		returnValue = F("Bei der Lehmkaute");
		break;
	}
	case 618:
	{
		returnValue = F("Bei der Lind");
		break;
	}
	case 619:
	{
		returnValue = F("Bei der Tränke");
		break;
	}
	case 620:
	{
		returnValue = F("Beim Welschengarten");
		break;
	}
	case 621:
	{
		returnValue = F("Bellersheimer Straße");
		break;
	}
	case 622:
	{
		returnValue = F("Beltershainer Straße");
		break;
	}
	case 623:
	{
		returnValue = F("Bennergasse");
		break;
	}
	case 624:
	{
		returnValue = F("Bergermühle");
		break;
	}
	case 625:
	{
		returnValue = F("Berggartenstraße");
		break;
	}
	case 626:
	{
		returnValue = F("Bergheimer Straße");
		break;
	}
	case 627:
	{
		returnValue = F("Berghof");
		break;
	}
	case 628:
	{
		returnValue = F("Bergstraße");
		break;
	}
	case 629:
	{
		returnValue = F("Bergwaldstraße");
		break;
	}
	case 630:
	{
		returnValue = F("Bergweg");
		break;
	}
	case 631:
	{
		returnValue = F("Bergwerk");
		break;
	}
	case 632:
	{
		returnValue = F("Bergwerkstraße");
		break;
	}
	case 633:
	{
		returnValue = F("Berkenhoffstraße");
		break;
	}
	case 634:
	{
		returnValue = F("Berliner Platz");
		break;
	}
	case 635:
	{
		returnValue = F("Berliner Straße");
		break;
	}
	case 636:
	{
		returnValue = F("Berliner Weg");
		break;
	}
	case 637:
	{
		returnValue = F("Bernbachstraße");
		break;
	}
	case 638:
	{
		returnValue = F("Bernhard-Itzel-Straße");
		break;
	}
	case 639:
	{
		returnValue = F("Bernhardtstraße");
		break;
	}
	case 640:
	{
		returnValue = F("Bernsfelder Straße");
		break;
	}
	case 641:
	{
		returnValue = F("Bersröder Straße");
		break;
	}
	case 642:
	{
		returnValue = F("Bersröder Weg");
		break;
	}
	case 643:
	{
		returnValue = F("Bertha-von-Suttner-Weg");
		break;
	}
	case 644:
	{
		returnValue = F("Beskidenstraße");
		break;
	}
	case 645:
	{
		returnValue = F("Bessinger Straße");
		break;
	}
	case 646:
	{
		returnValue = F("Bettenberg");
		break;
	}
	case 647:
	{
		returnValue = F("Bettenhäuser Straße");
		break;
	}
	case 648:
	{
		returnValue = F("Bettina-von-Arnim-Straße");
		break;
	}
	case 649:
	{
		returnValue = F("Betzenröder Straße");
		break;
	}
	case 650:
	{
		returnValue = F("Beuerner Pfad");
		break;
	}
	case 651:
	{
		returnValue = F("Beuerner Straße");
		break;
	}
	case 652:
	{
		returnValue = F("Beuerner Weg");
		break;
	}
	case 653:
	{
		returnValue = F("Beune");
		break;
	}
	case 654:
	{
		returnValue = F("Beunestraße");
		break;
	}
	case 655:
	{
		returnValue = F("Beuneweg");
		break;
	}
	case 656:
	{
		returnValue = F("Beurer Weg");
		break;
	}
	case 657:
	{
		returnValue = F("Bieberstraße");
		break;
	}
	case 658:
	{
		returnValue = F("Bieneckstraße");
		break;
	}
	case 659:
	{
		returnValue = F("Biengartenweg");
		break;
	}
	case 660:
	{
		returnValue = F("Bingmühle");
		break;
	}
	case 661:
	{
		returnValue = F("Birkborn");
		break;
	}
	case 662:
	{
		returnValue = F("Birkenallee");
		break;
	}
	case 663:
	{
		returnValue = F("Birkengraben");
		break;
	}
	case 664:
	{
		returnValue = F("Birkenhof");
		break;
	}
	case 665:
	{
		returnValue = F("Birkenstraße");
		break;
	}
	case 666:
	{
		returnValue = F("Birkenweg");
		break;
	}
	case 667:
	{
		returnValue = F("Birklarer Weg");
		break;
	}
	case 668:
	{
		returnValue = F("Birnkheimer Hof");
		break;
	}
	case 669:
	{
		returnValue = F("Bismarckstraße");
		break;
	}
	case 670:
	{
		returnValue = F("Bitzenstraße");
		break;
	}
	case 671:
	{
		returnValue = F("Blackenstraße");
		break;
	}
	case 672:
	{
		returnValue = F("Blankhof");
		break;
	}
	case 673:
	{
		returnValue = F("Blankweg");
		break;
	}
	case 674:
	{
		returnValue = F("Blauäcker Weg");
		break;
	}
	case 675:
	{
		returnValue = F("Bleichgasse");
		break;
	}
	case 676:
	{
		returnValue = F("Bleichstraße");
		break;
	}
	case 677:
	{
		returnValue = F("Blütenweg");
		break;
	}
	case 678:
	{
		returnValue = F("Blumenring");
		break;
	}
	case 679:
	{
		returnValue = F("Blumenstraße");
		break;
	}
	case 680:
	{
		returnValue = F("Bodelschwinghweg");
		break;
	}
	case 681:
	{
		returnValue = F("Bodenweg");
		break;
	}
	case 682:
	{
		returnValue = F("Böcklinstraße");
		break;
	}
	case 683:
	{
		returnValue = F("Böhmerwald");
		break;
	}
	case 684:
	{
		returnValue = F("Bölzpfad");
		break;
	}
	case 685:
	{
		returnValue = F("Börnchesgall");
		break;
	}
	case 686:
	{
		returnValue = F("Börneweg");
		break;
	}
	case 687:
	{
		returnValue = F("Bogengasse");
		break;
	}
	case 688:
	{
		returnValue = F("Bogenstraße");
		break;
	}
	case 689:
	{
		returnValue = F("Bollnbacher Straße");
		break;
	}
	case 690:
	{
		returnValue = F("Bomberger Weg");
		break;
	}
	case 691:
	{
		returnValue = F("Bonhoefferstraße");
		break;
	}
	case 692:
	{
		returnValue = F("Bonifatiusweg");
		break;
	}
	case 693:
	{
		returnValue = F("Bootshausstraße");
		break;
	}
	case 694:
	{
		returnValue = F("Bornbachstraße");
		break;
	}
	case 695:
	{
		returnValue = F("Borngasse");
		break;
	}
	case 696:
	{
		returnValue = F("Bornhöll");
		break;
	}
	case 697:
	{
		returnValue = F("Bornrain");
		break;
	}
	case 698:
	{
		returnValue = F("Bornstraße");
		break;
	}
	case 699:
	{
		returnValue = F("Bornweg");
		break;
	}
	case 700:
	{
		returnValue = F("Bornwiesenweg");
		break;
	}
	case 701:
	{
		returnValue = F("Brahmsstraße");
		break;
	}
	case 702:
	{
		returnValue = F("Brandgasse");
		break;
	}
	case 703:
	{
		returnValue = F("Brandplatz");
		break;
	}
	case 704:
	{
		returnValue = F("Brandweg");
		break;
	}
	case 705:
	{
		returnValue = F("Braugasse");
		break;
	}
	case 706:
	{
		returnValue = F("Brauhausgasse");
		break;
	}
	case 707:
	{
		returnValue = F("Brauhausstraße");
		break;
	}
	case 708:
	{
		returnValue = F("Brauhofstraße");
		break;
	}
	case 709:
	{
		returnValue = F("Breiter Weg");
		break;
	}
	case 710:
	{
		returnValue = F("Breiteweg");
		break;
	}
	case 711:
	{
		returnValue = F("Breitgasse");
		break;
	}
	case 712:
	{
		returnValue = F("Brennofenstraße");
		break;
	}
	case 713:
	{
		returnValue = F("Brentanostraße");
		break;
	}
	case 714:
	{
		returnValue = F("Breslauer Straße");
		break;
	}
	case 715:
	{
		returnValue = F("Brodbachstraße");
		break;
	}
	case 716:
	{
		returnValue = F("Bromberger Straße");
		break;
	}
	case 717:
	{
		returnValue = F("Bruchgasse");
		break;
	}
	case 718:
	{
		returnValue = F("Bruchstraße");
		break;
	}
	case 719:
	{
		returnValue = F("Bruchweg");
		break;
	}
	case 720:
	{
		returnValue = F("Brucknerstraße");
		break;
	}
	case 721:
	{
		returnValue = F("Brückelchen");
		break;
	}
	case 722:
	{
		returnValue = F("Brückenstraße");
		break;
	}
	case 723:
	{
		returnValue = F("Brückgasse");
		break;
	}
	case 724:
	{
		returnValue = F("Brückweg");
		break;
	}
	case 725:
	{
		returnValue = F("Brüder-Grimm-Straße");
		break;
	}
	case 726:
	{
		returnValue = F("Brühgasse");
		break;
	}
	case 727:
	{
		returnValue = F("Brühlgasse");
		break;
	}
	case 728:
	{
		returnValue = F("Brühlstraße");
		break;
	}
	case 729:
	{
		returnValue = F("Brühlsweg");
		break;
	}
	case 730:
	{
		returnValue = F("Brumlikweg");
		break;
	}
	case 731:
	{
		returnValue = F("Brunnengasse");
		break;
	}
	case 732:
	{
		returnValue = F("Brunnenstraße");
		break;
	}
	case 733:
	{
		returnValue = F("Brunnental");
		break;
	}
	case 734:
	{
		returnValue = F("Brunnenweg");
		break;
	}
	case 735:
	{
		returnValue = F("Bubenrod");
		break;
	}
	case 736:
	{
		returnValue = F("Buchegasse");
		break;
	}
	case 737:
	{
		returnValue = F("Buchenring");
		break;
	}
	case 738:
	{
		returnValue = F("Buchenstraße");
		break;
	}
	case 739:
	{
		returnValue = F("Buchenweg");
		break;
	}
	case 740:
	{
		returnValue = F("Buchnerstraße");
		break;
	}
	case 741:
	{
		returnValue = F("Buchwaldstraße");
		break;
	}
	case 742:
	{
		returnValue = F("Buddestraße");
		break;
	}
	case 743:
	{
		returnValue = F("Buderusstraße");
		break;
	}
	case 744:
	{
		returnValue = F("Buderusweg");
		break;
	}
	case 745:
	{
		returnValue = F("Büchnerstraße");
		break;
	}
	case 746:
	{
		returnValue = F("Bückingstraße");
		break;
	}
	case 747:
	{
		returnValue = F("Bürgelweg");
		break;
	}
	case 748:
	{
		returnValue = F("Bürgerhausstraße");
		break;
	}
	case 749:
	{
		returnValue = F("Bürgermeister-Jung-Weg");
		break;
	}
	case 750:
	{
		returnValue = F("Burgackerweg");
		break;
	}
	case 751:
	{
		returnValue = F("Burgblick");
		break;
	}
	case 752:
	{
		returnValue = F("Burgenring");
		break;
	}
	case 753:
	{
		returnValue = F("Burggartenstraße");
		break;
	}
	case 754:
	{
		returnValue = F("Burggasse");
		break;
	}
	case 755:
	{
		returnValue = F("Burggraben");
		break;
	}
	case 756:
	{
		returnValue = F("Burggrabenstraße");
		break;
	}
	case 757:
	{
		returnValue = F("Burghain");
		break;
	}
	case 758:
	{
		returnValue = F("Burghof");
		break;
	}
	case 759:
	{
		returnValue = F("Burgmühlenweg");
		break;
	}
	case 760:
	{
		returnValue = F("Burgstraße");
		break;
	}
	case 761:
	{
		returnValue = F("Burgweg");
		break;
	}
	case 762:
	{
		returnValue = F("Burgwiesenweg");
		break;
	}
	case 763:
	{
		returnValue = F("Burkhardsfelder Straße");
		break;
	}
	case 764:
	{
		returnValue = F("Busecker Straße");
		break;
	}
	case 765:
	{
		returnValue = F("Busecker Weg");
		break;
	}
	case 766:
	{
		returnValue = F("Bussardweg");
		break;
	}
	case 767:
	{
		returnValue = F("Butzbacher Pforte");
		break;
	}
	case 768:
	{
		returnValue = F("Butzbacher Straße");
		break;
	}
	case 769:
	{
		returnValue = F("Canonstraße");
		break;
	}
	case 770:
	{
		returnValue = F("Carl-Barnas-Straße");
		break;
	}
	case 771:
	{
		returnValue = F("Carl-Benz-Ring");
		break;
	}
	case 772:
	{
		returnValue = F("Carl-Benz-Straße");
		break;
	}
	case 773:
	{
		returnValue = F("Carl-Franz-Straße");
		break;
	}
	case 774:
	{
		returnValue = F("Carl-Geist-Straße");
		break;
	}
	case 775:
	{
		returnValue = F("Carl-Maria-von-Weber-Straße");
		break;
	}
	case 776:
	{
		returnValue = F("Carl-Spitzweg-Straße");
		break;
	}
	case 777:
	{
		returnValue = F("Carl-Ulrich-Straße");
		break;
	}
	case 778:
	{
		returnValue = F("Carl-Vogt-Straße");
		break;
	}
	case 779:
	{
		returnValue = F("Carlo-Mierendorff-Straße");
		break;
	}
	case 780:
	{
		returnValue = F("Caspar-Reinhard-Straße");
		break;
	}
	case 781:
	{
		returnValue = F("Cervinusstraße");
		break;
	}
	case 782:
	{
		returnValue = F("Chamissoweg");
		break;
	}
	case 783:
	{
		returnValue = F("Charlottenburg");
		break;
	}
	case 784:
	{
		returnValue = F("Chattenhof");
		break;
	}
	case 785:
	{
		returnValue = F("Chemnitzer Straße");
		break;
	}
	case 786:
	{
		returnValue = F("Chopinstraße");
		break;
	}
	case 787:
	{
		returnValue = F("Christian-Ebeling-Straße");
		break;
	}
	case 788:
	{
		returnValue = F("Christian-Faber-Weg");
		break;
	}
	case 789:
	{
		returnValue = F("Christian-Rinck-Straße");
		break;
	}
	case 790:
	{
		returnValue = F("Christoph-Rübsamen-Steg");
		break;
	}
	case 791:
	{
		returnValue = F("Clara-Schumann-Straße");
		break;
	}
	case 792:
	{
		returnValue = F("Cleeberger Straße");
		break;
	}
	case 793:
	{
		returnValue = F("Clementiastraße");
		break;
	}
	case 794:
	{
		returnValue = F("Clevelandstraße");
		break;
	}
	case 795:
	{
		returnValue = F("Climbacher Weg");
		break;
	}
	case 796:
	{
		returnValue = F("Colemanstraße");
		break;
	}
	case 797:
	{
		returnValue = F("Condomer Straße");
		break;
	}
	case 798:
	{
		returnValue = F("Cottbuser Straße");
		break;
	}
	case 799:
	{
		returnValue = F("Cranachstraße");
		break;
	}
	case 800:
	{
		returnValue = F("Crednerstraße");
		break;
	}
	case 801:
	{
		returnValue = F("Cullmannsfahrt");
		break;
	}
	case 802:
	{
		returnValue = F("Curtmannstraße");
		break;
	}
	case 803:
	{
		returnValue = F("Dachsgang");
		break;
	}
	case 804:
	{
		returnValue = F("Dahlienstraße");
		break;
	}
	case 805:
	{
		returnValue = F("Dahlienweg");
		break;
	}
	case 806:
	{
		returnValue = F("Daimlerstraße");
		break;
	}
	case 807:
	{
		returnValue = F("Dalmesberg");
		break;
	}
	case 808:
	{
		returnValue = F("Dammstraße");
		break;
	}
	case 809:
	{
		returnValue = F("Dammweg");
		break;
	}
	case 810:
	{
		returnValue = F("Danziger Straße");
		break;
	}
	case 811:
	{
		returnValue = F("Daubringer Paß");
		break;
	}
	case 812:
	{
		returnValue = F("Daubringer Straße");
		break;
	}
	case 813:
	{
		returnValue = F("Denkmalsweg");
		break;
	}
	case 814:
	{
		returnValue = F("Deponiestraße");
		break;
	}
	case 815:
	{
		returnValue = F("Der Lustgarten");
		break;
	}
	case 816:
	{
		returnValue = F("Dessauer Straße");
		break;
	}
	case 817:
	{
		returnValue = F("Dexionstraße");
		break;
	}
	case 818:
	{
		returnValue = F("Didierstraße");
		break;
	}
	case 819:
	{
		returnValue = F("Die Bangärten");
		break;
	}
	case 820:
	{
		returnValue = F("Die Beu");
		break;
	}
	case 821:
	{
		returnValue = F("Die Falltorgärten");
		break;
	}
	case 822:
	{
		returnValue = F("Die Fünf Morgen");
		break;
	}
	case 823:
	{
		returnValue = F("Die Grohbach");
		break;
	}
	case 824:
	{
		returnValue = F("Die Heilige Seite");
		break;
	}
	case 825:
	{
		returnValue = F("Die Hohl");
		break;
	}
	case 826:
	{
		returnValue = F("Die Mühlgärten");
		break;
	}
	case 827:
	{
		returnValue = F("Die Scheuergärten");
		break;
	}
	case 828:
	{
		returnValue = F("Die Tränke");
		break;
	}
	case 829:
	{
		returnValue = F("Die Wiesengärten");
		break;
	}
	case 830:
	{
		returnValue = F("Die Winke");
		break;
	}
	case 831:
	{
		returnValue = F("Diebsturmstraße");
		break;
	}
	case 832:
	{
		returnValue = F("Diebweg");
		break;
	}
	case 833:
	{
		returnValue = F("Dienbergstraße");
		break;
	}
	case 834:
	{
		returnValue = F("Dieselstraße");
		break;
	}
	case 835:
	{
		returnValue = F("Dietrich-Bonhöffer-Straße");
		break;
	}
	case 836:
	{
		returnValue = F("Dietrich-Bonhoeffer-Straße");
		break;
	}
	case 837:
	{
		returnValue = F("Dietrich-Bonhoeffer-Weg");
		break;
	}
	case 838:
	{
		returnValue = F("Dieulefiter Straße");
		break;
	}
	case 839:
	{
		returnValue = F("Diezstraße");
		break;
	}
	case 840:
	{
		returnValue = F("Dippemühle");
		break;
	}
	case 841:
	{
		returnValue = F("Döllebach");
		break;
	}
	case 842:
	{
		returnValue = F("Dörfelsweg");
		break;
	}
	case 843:
	{
		returnValue = F("Döringstraße");
		break;
	}
	case 844:
	{
		returnValue = F("Dörnbachstraße");
		break;
	}
	case 845:
	{
		returnValue = F("Dörrenbergweg");
		break;
	}
	case 846:
	{
		returnValue = F("Domäne Schiffenberg");
		break;
	}
	case 847:
	{
		returnValue = F("Dorf-Güller Straße");
		break;
	}
	case 848:
	{
		returnValue = F("Dorf-Güller Weg");
		break;
	}
	case 849:
	{
		returnValue = F("Dorfanger");
		break;
	}
	case 850:
	{
		returnValue = F("Dorfstraße");
		break;
	}
	case 851:
	{
		returnValue = F("Dorothea-Razumovsky-Straße");
		break;
	}
	case 852:
	{
		returnValue = F("Dreieck");
		break;
	}
	case 853:
	{
		returnValue = F("Dreilindenweg");
		break;
	}
	case 854:
	{
		returnValue = F("Dreispitz");
		break;
	}
	case 855:
	{
		returnValue = F("Dreitannenhof");
		break;
	}
	case 856:
	{
		returnValue = F("Dresdener Straße");
		break;
	}
	case 857:
	{
		returnValue = F("Drongasse");
		break;
	}
	case 858:
	{
		returnValue = F("Drosselpfad");
		break;
	}
	case 859:
	{
		returnValue = F("Drosselweg");
		break;
	}
	case 860:
	{
		returnValue = F("Dünsberger Weg");
		break;
	}
	case 861:
	{
		returnValue = F("Dünsbergheim");
		break;
	}
	case 862:
	{
		returnValue = F("Dünsbergring");
		break;
	}
	case 863:
	{
		returnValue = F("Dünsbergstraße");
		break;
	}
	case 864:
	{
		returnValue = F("Dürerstraße");
		break;
	}
	case 865:
	{
		returnValue = F("Dutenhofener Straße");
		break;
	}
	case 866:
	{
		returnValue = F("Ebelstraße");
		break;
	}
	case 867:
	{
		returnValue = F("Eberstädter Weg");
		break;
	}
	case 868:
	{
		returnValue = F("Ecke");
		break;
	}
	case 869:
	{
		returnValue = F("Eckgasse");
		break;
	}
	case 870:
	{
		returnValue = F("Eckstraße");
		break;
	}
	case 871:
	{
		returnValue = F("Edda-Seydel-Richter-Straße");
		break;
	}
	case 872:
	{
		returnValue = F("Edekastraße");
		break;
	}
	case 873:
	{
		returnValue = F("Ederstraße");
		break;
	}
	case 874:
	{
		returnValue = F("Editha-Klipstein-Weg");
		break;
	}
	case 875:
	{
		returnValue = F("Edlef-Köppen-Weg");
		break;
	}
	case 876:
	{
		returnValue = F("Eduard-David-Straße");
		break;
	}
	case 877:
	{
		returnValue = F("Egelseeweg");
		break;
	}
	case 878:
	{
		returnValue = F("Egerländer Straße");
		break;
	}
	case 879:
	{
		returnValue = F("Egerlandstraße");
		break;
	}
	case 880:
	{
		returnValue = F("Egerstraße");
		break;
	}
	case 881:
	{
		returnValue = F("Ehrsamer Weg");
		break;
	}
	case 882:
	{
		returnValue = F("Eichäcker");
		break;
	}
	case 883:
	{
		returnValue = F("Eichendorffring");
		break;
	}
	case 884:
	{
		returnValue = F("Eichendorffstraße");
		break;
	}
	case 885:
	{
		returnValue = F("Eichenring");
		break;
	}
	case 886:
	{
		returnValue = F("Eichenröder Weg");
		break;
	}
	case 887:
	{
		returnValue = F("Eichenstraße");
		break;
	}
	case 888:
	{
		returnValue = F("Eichenweg");
		break;
	}
	case 889:
	{
		returnValue = F("Eichgärten");
		break;
	}
	case 890:
	{
		returnValue = F("Eichgärtenallee");
		break;
	}
	case 891:
	{
		returnValue = F("Eichgartenweg");
		break;
	}
	case 892:
	{
		returnValue = F("Eichgasse");
		break;
	}
	case 893:
	{
		returnValue = F("Eichheckehof");
		break;
	}
	case 894:
	{
		returnValue = F("Eichstachelstraße");
		break;
	}
	case 895:
	{
		returnValue = F("Eichstraße");
		break;
	}
	case 896:
	{
		returnValue = F("Eichweg");
		break;
	}
	case 897:
	{
		returnValue = F("Einshäuser Weg");
		break;
	}
	case 898:
	{
		returnValue = F("Eisenacher Straße");
		break;
	}
	case 899:
	{
		returnValue = F("Eisenbergstraße");
		break;
	}
	case 900:
	{
		returnValue = F("Eisenkauterweg");
		break;
	}
	case 901:
	{
		returnValue = F("Eisenstein");
		break;
	}
	case 902:
	{
		returnValue = F("Eiserne Hand");
		break;
	}
	case 903:
	{
		returnValue = F("Elisabeth-Schwarzhaupt-Straße");
		break;
	}
	case 904:
	{
		returnValue = F("Elisabethenstraße");
		break;
	}
	case 905:
	{
		returnValue = F("Elly-Heuss-Knapp-Weg");
		break;
	}
	case 906:
	{
		returnValue = F("Elsa-Brandström-Straße");
		break;
	}
	case 907:
	{
		returnValue = F("Elsternhorst");
		break;
	}
	case 908:
	{
		returnValue = F("Eltersberg");
		break;
	}
	case 909:
	{
		returnValue = F("Embachweg");
		break;
	}
	case 910:
	{
		returnValue = F("Emdestraße");
		break;
	}
	case 911:
	{
		returnValue = F("Emilie-Feuster-Straße");
		break;
	}
	case 912:
	{
		returnValue = F("Endersstraße");
		break;
	}
	case 913:
	{
		returnValue = F("Engelshäuser Berg");
		break;
	}
	case 914:
	{
		returnValue = F("Enggasse");
		break;
	}
	case 915:
	{
		returnValue = F("Ennelbachstraße");
		break;
	}
	case 916:
	{
		returnValue = F("Erbsengasse");
		break;
	}
	case 917:
	{
		returnValue = F("Erdaer Straße");
		break;
	}
	case 918:
	{
		returnValue = F("Erdkauter Weg");
		break;
	}
	case 919:
	{
		returnValue = F("Erfurter Straße");
		break;
	}
	case 920:
	{
		returnValue = F("Erich-Carl-Arabin-Straße");
		break;
	}
	case 921:
	{
		returnValue = F("Erich-Kästner-Straße");
		break;
	}
	case 922:
	{
		returnValue = F("Erlengasse");
		break;
	}
	case 923:
	{
		returnValue = F("Erlenhof");
		break;
	}
	case 924:
	{
		returnValue = F("Erlenstraße");
		break;
	}
	case 925:
	{
		returnValue = F("Erlenweg");
		break;
	}
	case 926:
	{
		returnValue = F("Erlesbergstraße");
		break;
	}
	case 927:
	{
		returnValue = F("Ermelgasse");
		break;
	}
	case 928:
	{
		returnValue = F("Erna-Sack-Straße");
		break;
	}
	case 929:
	{
		returnValue = F("Ernst-Eckstein-Straße");
		break;
	}
	case 930:
	{
		returnValue = F("Ernst-Leitz-Straße");
		break;
	}
	case 931:
	{
		returnValue = F("Ernst-Ludwig-Straße");
		break;
	}
	case 932:
	{
		returnValue = F("Ernst-Steiner-Straße");
		break;
	}
	case 933:
	{
		returnValue = F("Ernst-Toller-Weg");
		break;
	}
	case 934:
	{
		returnValue = F("Ernststraße");
		break;
	}
	case 935:
	{
		returnValue = F("Erwin-Stein-Straße");
		break;
	}
	case 936:
	{
		returnValue = F("Erzweg");
		break;
	}
	case 937:
	{
		returnValue = F("Eschenweg");
		break;
	}
	case 938:
	{
		returnValue = F("Eselspfad");
		break;
	}
	case 939:
	{
		returnValue = F("Espaer Straße");
		break;
	}
	case 940:
	{
		returnValue = F("Espenstraße");
		break;
	}
	case 941:
	{
		returnValue = F("Essener Weg");
		break;
	}
	case 942:
	{
		returnValue = F("Ettingshäuser Straße");
		break;
	}
	case 943:
	{
		returnValue = F("Eulenkopf");
		break;
	}
	case 944:
	{
		returnValue = F("Eulenring");
		break;
	}
	case 945:
	{
		returnValue = F("Europastraße");
		break;
	}
	case 946:
	{
		returnValue = F("Ezetilstraße");
		break;
	}
	case 947:
	{
		returnValue = F("Fahrt");
		break;
	}
	case 948:
	{
		returnValue = F("Fahrtgasse");
		break;
	}
	case 949:
	{
		returnValue = F("Falkenring");
		break;
	}
	case 950:
	{
		returnValue = F("Falkenstraße");
		break;
	}
	case 951:
	{
		returnValue = F("Falkenweg");
		break;
	}
	case 952:
	{
		returnValue = F("Falkweg");
		break;
	}
	case 953:
	{
		returnValue = F("Falltorgasse");
		break;
	}
	case 954:
	{
		returnValue = F("Falltorstraße");
		break;
	}
	case 955:
	{
		returnValue = F("Falterstraße");
		break;
	}
	case 956:
	{
		returnValue = F("Fasanenweg");
		break;
	}
	case 957:
	{
		returnValue = F("Fasanerie");
		break;
	}
	case 958:
	{
		returnValue = F("Feldgarten");
		break;
	}
	case 959:
	{
		returnValue = F("Feldgräben");
		break;
	}
	case 960:
	{
		returnValue = F("Feldheimer Straße");
		break;
	}
	case 961:
	{
		returnValue = F("Feldstraße");
		break;
	}
	case 962:
	{
		returnValue = F("Feldwiesenstraße");
		break;
	}
	case 963:
	{
		returnValue = F("Felix-Klipstein-Weg");
		break;
	}
	case 964:
	{
		returnValue = F("Fellingshäuser Straße");
		break;
	}
	case 965:
	{
		returnValue = F("Felsenstraße");
		break;
	}
	case 966:
	{
		returnValue = F("Felsenweg");
		break;
	}
	case 967:
	{
		returnValue = F("Felsstraße");
		break;
	}
	case 968:
	{
		returnValue = F("Felsweg");
		break;
	}
	case 969:
	{
		returnValue = F("Ferdinand-Porsche-Straße");
		break;
	}
	case 970:
	{
		returnValue = F("Ferniestraße");
		break;
	}
	case 971:
	{
		returnValue = F("Feuerbachstraße");
		break;
	}
	case 972:
	{
		returnValue = F("Feulgenstraße");
		break;
	}
	case 973:
	{
		returnValue = F("Fichtenstraße");
		break;
	}
	case 974:
	{
		returnValue = F("Fichtenweg");
		break;
	}
	case 975:
	{
		returnValue = F("Fichtestraße");
		break;
	}
	case 976:
	{
		returnValue = F("Finkenbusch");
		break;
	}
	case 977:
	{
		returnValue = F("Finkenweg");
		break;
	}
	case 978:
	{
		returnValue = F("Fischbach");
		break;
	}
	case 979:
	{
		returnValue = F("Fischerweg");
		break;
	}
	case 980:
	{
		returnValue = F("Flachsbachweg");
		break;
	}
	case 981:
	{
		returnValue = F("Fleckenbergsweg");
		break;
	}
	case 982:
	{
		returnValue = F("Flensunger Straße");
		break;
	}
	case 983:
	{
		returnValue = F("Fliederstraße");
		break;
	}
	case 984:
	{
		returnValue = F("Fliederweg");
		break;
	}
	case 985:
	{
		returnValue = F("Fliednerweg");
		break;
	}
	case 986:
	{
		returnValue = F("Flößerweg");
		break;
	}
	case 987:
	{
		returnValue = F("Flugplatz");
		break;
	}
	case 988:
	{
		returnValue = F("Flugplatzstraße");
		break;
	}
	case 989:
	{
		returnValue = F("Flußgasse");
		break;
	}
	case 990:
	{
		returnValue = F("Flutgraben");
		break;
	}
	case 991:
	{
		returnValue = F("Fockestraße");
		break;
	}
	case 992:
	{
		returnValue = F("Förstergasse");
		break;
	}
	case 993:
	{
		returnValue = F("Fohnbachstraße");
		break;
	}
	case 994:
	{
		returnValue = F("Fontaneweg");
		break;
	}
	case 995:
	{
		returnValue = F("Forsthaus Breuersberg");
		break;
	}
	case 996:
	{
		returnValue = F("Forsthaus Dünsberg");
		break;
	}
	case 997:
	{
		returnValue = F("Forsthaus Friedelhausen");
		break;
	}
	case 998:
	{
		returnValue = F("Forsthaus Haina");
		break;
	}
	case 999:
	{
		returnValue = F("Forsthaus Waldhaus");
		break;
	}
	case 1000:
	{
		returnValue = F("Forsthausstraße");
		break;
	}
	case 1001:
	{
		returnValue = F("Forsthausweg");
		break;
	}
	case 1002:
	{
		returnValue = F("Forststraße");
		break;
	}
	case 1003:
	{
		returnValue = F("Forstweg");
		break;
	}
	case 1004:
	{
		returnValue = F("Fortweg");
		break;
	}
	case 1005:
	{
		returnValue = F("Frankenbacher Straße");
		break;
	}
	case 1006:
	{
		returnValue = F("Frankfurter Straße");
		break;
	}
	case 1007:
	{
		returnValue = F("Franzen Garten");
		break;
	}
	case 1008:
	{
		returnValue = F("Franzensbader Straße");
		break;
	}
	case 1009:
	{
		returnValue = F("Freienseener Straße");
		break;
	}
	case 1010:
	{
		returnValue = F("Freienseener Weg");
		break;
	}
	case 1011:
	{
		returnValue = F("Freier Platz");
		break;
	}
	case 1012:
	{
		returnValue = F("Freigasse");
		break;
	}
	case 1013:
	{
		returnValue = F("Freiheitsstraße");
		break;
	}
	case 1014:
	{
		returnValue = F("Freiherr-vom-Stein-Straße");
		break;
	}
	case 1015:
	{
		returnValue = F("Freiligrathstraße");
		break;
	}
	case 1016:
	{
		returnValue = F("Friedberger Straße");
		break;
	}
	case 1017:
	{
		returnValue = F("Friedel-Münch-Straße");
		break;
	}
	case 1018:
	{
		returnValue = F("Friedelhausen");
		break;
	}
	case 1019:
	{
		returnValue = F("Friedensruh");
		break;
	}
	case 1020:
	{
		returnValue = F("Friedensstraße");
		break;
	}
	case 1021:
	{
		returnValue = F("Friedenstraße");
		break;
	}
	case 1022:
	{
		returnValue = F("Friedhofsallee");
		break;
	}
	case 1023:
	{
		returnValue = F("Friedhofstraße");
		break;
	}
	case 1024:
	{
		returnValue = F("Friedhofsweg");
		break;
	}
	case 1025:
	{
		returnValue = F("Friedlandstraße");
		break;
	}
	case 1026:
	{
		returnValue = F("Friedrich-Ebert-Straße");
		break;
	}
	case 1027:
	{
		returnValue = F("Friedrich-Keller-Straße");
		break;
	}
	case 1028:
	{
		returnValue = F("Friedrich-List-Straße");
		break;
	}
	case 1029:
	{
		returnValue = F("Friedrich-Löll-Straße");
		break;
	}
	case 1030:
	{
		returnValue = F("Friedrich-Naumann-Straße");
		break;
	}
	case 1031:
	{
		returnValue = F("Friedrich-Schwarz-Straße");
		break;
	}
	case 1032:
	{
		returnValue = F("Friedrichshütte");
		break;
	}
	case 1033:
	{
		returnValue = F("Friedrichstraße");
		break;
	}
	case 1034:
	{
		returnValue = F("Fröbelstraße");
		break;
	}
	case 1035:
	{
		returnValue = F("Fröschen Weiher");
		break;
	}
	case 1036:
	{
		returnValue = F("Fronhäuser Straße");
		break;
	}
	case 1037:
	{
		returnValue = F("Fronhofstraße");
		break;
	}
	case 1038:
	{
		returnValue = F("Froschgasse");
		break;
	}
	case 1039:
	{
		returnValue = F("Fuchsgraben");
		break;
	}
	case 1040:
	{
		returnValue = F("Fünfhausen");
		break;
	}
	case 1041:
	{
		returnValue = F("Fuldaer Straße");
		break;
	}
	case 1042:
	{
		returnValue = F("Fuldastraße");
		break;
	}
	case 1043:
	{
		returnValue = F("Gabelsbergerstraße");
		break;
	}
	case 1044:
	{
		returnValue = F("Gänsmühle");
		break;
	}
	case 1045:
	{
		returnValue = F("Gaffkystraße");
		break;
	}
	case 1046:
	{
		returnValue = F("Galgenberg");
		break;
	}
	case 1047:
	{
		returnValue = F("Galgenbergsweg");
		break;
	}
	case 1048:
	{
		returnValue = F("Gallusstraße");
		break;
	}
	case 1049:
	{
		returnValue = F("Gambacher Weg");
		break;
	}
	case 1050:
	{
		returnValue = F("Gansahrweg");
		break;
	}
	case 1051:
	{
		returnValue = F("Ganseburg");
		break;
	}
	case 1052:
	{
		returnValue = F("Garbenteicher Straße");
		break;
	}
	case 1053:
	{
		returnValue = F("Garbenteicher Weg");
		break;
	}
	case 1054:
	{
		returnValue = F("Gartenbergstraße");
		break;
	}
	case 1055:
	{
		returnValue = F("Gartenstraße");
		break;
	}
	case 1056:
	{
		returnValue = F("Gartenweg");
		break;
	}
	case 1057:
	{
		returnValue = F("Gartfeld");
		break;
	}
	case 1058:
	{
		returnValue = F("Gaulbach");
		break;
	}
	case 1059:
	{
		returnValue = F("Gaulskopf");
		break;
	}
	case 1060:
	{
		returnValue = F("Gaulskopfring");
		break;
	}
	case 1061:
	{
		returnValue = F("Gebertshäuser Weg");
		break;
	}
	case 1062:
	{
		returnValue = F("Gefängnisweg");
		break;
	}
	case 1063:
	{
		returnValue = F("Gehrenweg");
		break;
	}
	case 1064:
	{
		returnValue = F("Geilshäuser Weg");
		break;
	}
	case 1065:
	{
		returnValue = F("Gellertweg");
		break;
	}
	case 1066:
	{
		returnValue = F("Georg-Büchner-Straße");
		break;
	}
	case 1067:
	{
		returnValue = F("Georg-Edward-Straße");
		break;
	}
	case 1068:
	{
		returnValue = F("Georg-Elser-Straße");
		break;
	}
	case 1069:
	{
		returnValue = F("Georg-Frank-Straße");
		break;
	}
	case 1070:
	{
		returnValue = F("Georg-Haas-Straße");
		break;
	}
	case 1071:
	{
		returnValue = F("Georg-Philipp-Gail-Straße");
		break;
	}
	case 1072:
	{
		returnValue = F("Georg-Schlosser-Straße");
		break;
	}
	case 1073:
	{
		returnValue = F("Georgenhammer");
		break;
	}
	case 1074:
	{
		returnValue = F("Geraer Straße");
		break;
	}
	case 1075:
	{
		returnValue = F("Geranienhof");
		break;
	}
	case 1076:
	{
		returnValue = F("Geranienweg");
		break;
	}
	case 1077:
	{
		returnValue = F("Gerberaweg");
		break;
	}
	case 1078:
	{
		returnValue = F("Gerhart-Hauptmann-Straße");
		break;
	}
	case 1079:
	{
		returnValue = F("Gerichtsspitz");
		break;
	}
	case 1080:
	{
		returnValue = F("Gerichtsstraße");
		break;
	}
	case 1081:
	{
		returnValue = F("Germaniastraße");
		break;
	}
	case 1082:
	{
		returnValue = F("Geschwister-Scholl-Straße");
		break;
	}
	case 1083:
	{
		returnValue = F("Gießener Pforte");
		break;
	}
	case 1084:
	{
		returnValue = F("Gießener Straße");
		break;
	}
	case 1085:
	{
		returnValue = F("Giessener Straße");
		break;
	}
	case 1086:
	{
		returnValue = F("Gießener Weg");
		break;
	}
	case 1087:
	{
		returnValue = F("Gimpelweg");
		break;
	}
	case 1088:
	{
		returnValue = F("Ginsterbusch");
		break;
	}
	case 1089:
	{
		returnValue = F("Ginsterweg");
		break;
	}
	case 1090:
	{
		returnValue = F("Gladenbacher Straße");
		break;
	}
	case 1091:
	{
		returnValue = F("Gladenbacher Weg");
		break;
	}
	case 1092:
	{
		returnValue = F("Gladiolenweg");
		break;
	}
	case 1093:
	{
		returnValue = F("Glaserweg");
		break;
	}
	case 1094:
	{
		returnValue = F("Glashütte");
		break;
	}
	case 1095:
	{
		returnValue = F("Glashüttenweg");
		break;
	}
	case 1096:
	{
		returnValue = F("Glatthaferweg");
		break;
	}
	case 1097:
	{
		returnValue = F("Glaubrechtstraße");
		break;
	}
	case 1098:
	{
		returnValue = F("Gleibachweg");
		break;
	}
	case 1099:
	{
		returnValue = F("Gleiberger Weg");
		break;
	}
	case 1100:
	{
		returnValue = F("Gleibergring");
		break;
	}
	case 1101:
	{
		returnValue = F("Gleibergstraße");
		break;
	}
	case 1102:
	{
		returnValue = F("Gleienbergweg");
		break;
	}
	case 1103:
	{
		returnValue = F("Glockenstraße");
		break;
	}
	case 1104:
	{
		returnValue = F("Gnauthstraße");
		break;
	}
	case 1105:
	{
		returnValue = F("Göbelnröder Straße");
		break;
	}
	case 1106:
	{
		returnValue = F("Göbelsgasse");
		break;
	}
	case 1107:
	{
		returnValue = F("Göllingsweg");
		break;
	}
	case 1108:
	{
		returnValue = F("Goethestraße");
		break;
	}
	case 1109:
	{
		returnValue = F("Göthestraße");
		break;
	}
	case 1110:
	{
		returnValue = F("Goldammerweg");
		break;
	}
	case 1111:
	{
		returnValue = F("Goldbergstraße");
		break;
	}
	case 1112:
	{
		returnValue = F("Goleszower Straße");
		break;
	}
	case 1113:
	{
		returnValue = F("Golfplatz Kolnhausen");
		break;
	}
	case 1114:
	{
		returnValue = F("Gombertsgasse");
		break;
	}
	case 1115:
	{
		returnValue = F("Gonterskirchner Weg");
		break;
	}
	case 1116:
	{
		returnValue = F("Gothaer Straße");
		break;
	}
	case 1117:
	{
		returnValue = F("Gottfried-Arnold-Straße");
		break;
	}
	case 1118:
	{
		returnValue = F("Gottfried-Keller-Straße");
		break;
	}
	case 1119:
	{
		returnValue = F("Gottlieb-Daimler-Straße");
		break;
	}
	case 1120:
	{
		returnValue = F("Graben");
		break;
	}
	case 1121:
	{
		returnValue = F("Grabenstraße");
		break;
	}
	case 1122:
	{
		returnValue = F("Grasgärten");
		break;
	}
	case 1123:
	{
		returnValue = F("Grasweg");
		break;
	}
	case 1124:
	{
		returnValue = F("Graudenzer Straße");
		break;
	}
	case 1125:
	{
		returnValue = F("Graudornstraße");
		break;
	}
	case 1126:
	{
		returnValue = F("Grebenwiesenweg");
		break;
	}
	case 1127:
	{
		returnValue = F("Gregor-Mendel-Straße");
		break;
	}
	case 1128:
	{
		returnValue = F("Greizer Straße");
		break;
	}
	case 1129:
	{
		returnValue = F("Grenzborn");
		break;
	}
	case 1130:
	{
		returnValue = F("Grenzweg");
		break;
	}
	case 1131:
	{
		returnValue = F("Grethenstraße");
		break;
	}
	case 1132:
	{
		returnValue = F("Grohgasse");
		break;
	}
	case 1133:
	{
		returnValue = F("Grohlgasse");
		break;
	}
	case 1134:
	{
		returnValue = F("Groß-Eichener Straße");
		break;
	}
	case 1135:
	{
		returnValue = F("Großen-Busecker-Straße");
		break;
	}
	case 1136:
	{
		returnValue = F("Grossen-Busecker Straße");
		break;
	}
	case 1137:
	{
		returnValue = F("Großen-Busecker Straße");
		break;
	}
	case 1138:
	{
		returnValue = F("Großen-Lindener-Straße");
		break;
	}
	case 1139:
	{
		returnValue = F("Grosser Morgen");
		break;
	}
	case 1140:
	{
		returnValue = F("Grosser Steinweg");
		break;
	}
	case 1141:
	{
		returnValue = F("Grossgasse");
		break;
	}
	case 1142:
	{
		returnValue = F("Großgasse");
		break;
	}
	case 1143:
	{
		returnValue = F("Grube Königsberg");
		break;
	}
	case 1144:
	{
		returnValue = F("Grubenstraße");
		break;
	}
	case 1145:
	{
		returnValue = F("Grünberger Straße");
		break;
	}
	case 1146:
	{
		returnValue = F("Grünberger Weg");
		break;
	}
	case 1147:
	{
		returnValue = F("Grünemannsgasse");
		break;
	}
	case 1148:
	{
		returnValue = F("Grüner Rasen");
		break;
	}
	case 1149:
	{
		returnValue = F("Grüner Weg");
		break;
	}
	case 1150:
	{
		returnValue = F("Grünes Meer");
		break;
	}
	case 1151:
	{
		returnValue = F("Grüninger Hof");
		break;
	}
	case 1152:
	{
		returnValue = F("Grüninger Straße");
		break;
	}
	case 1153:
	{
		returnValue = F("Grüninger Weg");
		break;
	}
	case 1154:
	{
		returnValue = F("Grundbergweg");
		break;
	}
	case 1155:
	{
		returnValue = F("Grundweg");
		break;
	}
	case 1156:
	{
		returnValue = F("Guckertsweg");
		break;
	}
	case 1157:
	{
		returnValue = F("Günthersgraben");
		break;
	}
	case 1158:
	{
		returnValue = F("Gustav-Heinemann-Straße");
		break;
	}
	case 1159:
	{
		returnValue = F("Gustav-Krüger-Straße");
		break;
	}
	case 1160:
	{
		returnValue = F("Gustav-Lorenz-Weg");
		break;
	}
	case 1161:
	{
		returnValue = F("Gustav-Stresemann-Ring");
		break;
	}
	case 1162:
	{
		returnValue = F("Gutenbergring");
		break;
	}
	case 1163:
	{
		returnValue = F("Gutenbergstraße");
		break;
	}
	case 1164:
	{
		returnValue = F("Gutfleischstraße");
		break;
	}
	case 1165:
	{
		returnValue = F("Haargärten");
		break;
	}
	case 1166:
	{
		returnValue = F("Habichtweg");
		break;
	}
	case 1167:
	{
		returnValue = F("Hachborner Straße");
		break;
	}
	case 1168:
	{
		returnValue = F("Händelstraße");
		break;
	}
	case 1169:
	{
		returnValue = F("Hässelsstraße");
		break;
	}
	case 1170:
	{
		returnValue = F("Häuser Born");
		break;
	}
	case 1171:
	{
		returnValue = F("Häusergasse");
		break;
	}
	case 1172:
	{
		returnValue = F("Hafergärten");
		break;
	}
	case 1173:
	{
		returnValue = F("Hafergarten");
		break;
	}
	case 1174:
	{
		returnValue = F("Hagstraße");
		break;
	}
	case 1175:
	{
		returnValue = F("Hahnstrauch");
		break;
	}
	case 1176:
	{
		returnValue = F("Hainaer Weg");
		break;
	}
	case 1177:
	{
		returnValue = F("Hainbachstraße");
		break;
	}
	case 1178:
	{
		returnValue = F("Hainerde");
		break;
	}
	case 1179:
	{
		returnValue = F("Hainerhof");
		break;
	}
	case 1180:
	{
		returnValue = F("Hainerweg");
		break;
	}
	case 1181:
	{
		returnValue = F("Haingasse");
		break;
	}
	case 1182:
	{
		returnValue = F("Haingraben");
		break;
	}
	case 1183:
	{
		returnValue = F("Hainholzgasse");
		break;
	}
	case 1184:
	{
		returnValue = F("Hainmauergasse");
		break;
	}
	case 1185:
	{
		returnValue = F("Hainstraße");
		break;
	}
	case 1186:
	{
		returnValue = F("Hainweg");
		break;
	}
	case 1187:
	{
		returnValue = F("Hallsche Straße");
		break;
	}
	case 1188:
	{
		returnValue = F("Hammerpfad");
		break;
	}
	case 1189:
	{
		returnValue = F("Hammstraße");
		break;
	}
	case 1190:
	{
		returnValue = F("Hangelsteinring");
		break;
	}
	case 1191:
	{
		returnValue = F("Hangelsteinstraße");
		break;
	}
	case 1192:
	{
		returnValue = F("Hangensteinstraße");
		break;
	}
	case 1193:
	{
		returnValue = F("Hangstraße");
		break;
	}
	case 1194:
	{
		returnValue = F("Hannah-Arendt-Straße");
		break;
	}
	case 1195:
	{
		returnValue = F("Hans-Böckler-Straße");
		break;
	}
	case 1196:
	{
		returnValue = F("Hans-Watzlik-Straße");
		break;
	}
	case 1197:
	{
		returnValue = F("Harbacher Straße");
		break;
	}
	case 1198:
	{
		returnValue = F("Harbstraße");
		break;
	}
	case 1199:
	{
		returnValue = F("Hardtallee");
		break;
	}
	case 1200:
	{
		returnValue = F("Hardtweg");
		break;
	}
	case 1201:
	{
		returnValue = F("Harnbachweg");
		break;
	}
	case 1202:
	{
		returnValue = F("Hartigstraße");
		break;
	}
	case 1203:
	{
		returnValue = F("Haselhof");
		break;
	}
	case 1204:
	{
		returnValue = F("Haselweg");
		break;
	}
	case 1205:
	{
		returnValue = F("Hasenecke");
		break;
	}
	case 1206:
	{
		returnValue = F("Hasenköppel");
		break;
	}
	case 1207:
	{
		returnValue = F("Hasenpfad");
		break;
	}
	case 1208:
	{
		returnValue = F("Hattenröder Straße");
		break;
	}
	case 1209:
	{
		returnValue = F("Hattenröder Weg");
		break;
	}
	case 1210:
	{
		returnValue = F("Haubsweg");
		break;
	}
	case 1211:
	{
		returnValue = F("Hauffstraße");
		break;
	}
	case 1212:
	{
		returnValue = F("Hauptstraße");
		break;
	}
	case 1213:
	{
		returnValue = F("Haus Käunzberg");
		break;
	}
	case 1214:
	{
		returnValue = F("Haus Launscheid");
		break;
	}
	case 1215:
	{
		returnValue = F("Haus Ziegelhütte");
		break;
	}
	case 1216:
	{
		returnValue = F("Hausener Straße");
		break;
	}
	case 1217:
	{
		returnValue = F("Haydnstraße");
		break;
	}
	case 1218:
	{
		returnValue = F("Heckenbergstraße");
		break;
	}
	case 1219:
	{
		returnValue = F("Hedtwigsweg");
		break;
	}
	case 1220:
	{
		returnValue = F("Hedwig-Burgheim-Ring");
		break;
	}
	case 1221:
	{
		returnValue = F("Heeggraben");
		break;
	}
	case 1222:
	{
		returnValue = F("Heegstrauchweg");
		break;
	}
	case 1223:
	{
		returnValue = F("Heegweg");
		break;
	}
	case 1224:
	{
		returnValue = F("Heergasse");
		break;
	}
	case 1225:
	{
		returnValue = F("Heerstraße");
		break;
	}
	case 1226:
	{
		returnValue = F("Heerweg");
		break;
	}
	case 1227:
	{
		returnValue = F("Heggrabenstraße");
		break;
	}
	case 1228:
	{
		returnValue = F("Hegstrauch");
		break;
	}
	case 1229:
	{
		returnValue = F("Hegweg");
		break;
	}
	case 1230:
	{
		returnValue = F("Hehlingsgrund");
		break;
	}
	case 1231:
	{
		returnValue = F("Heide");
		break;
	}
	case 1232:
	{
		returnValue = F("Heidestraße");
		break;
	}
	case 1233:
	{
		returnValue = F("Heidstraße");
		break;
	}
	case 1234:
	{
		returnValue = F("Heiloohsecke");
		break;
	}
	case 1235:
	{
		returnValue = F("Hein-Heckroth-Straße");
		break;
	}
	case 1236:
	{
		returnValue = F("Heinestraße");
		break;
	}
	case 1237:
	{
		returnValue = F("Heinrich-Buff-Ring");
		break;
	}
	case 1238:
	{
		returnValue = F("Heinrich-Deibel-Straße");
		break;
	}
	case 1239:
	{
		returnValue = F("Heinrich-Fourier-Straße");
		break;
	}
	case 1240:
	{
		returnValue = F("Heinrich-Heine-Straße");
		break;
	}
	case 1241:
	{
		returnValue = F("Heinrich-Hertz-Straße");
		break;
	}
	case 1242:
	{
		returnValue = F("Heinrich-Lübke-Ring");
		break;
	}
	case 1243:
	{
		returnValue = F("Heinrich-Neeb-Straße");
		break;
	}
	case 1244:
	{
		returnValue = F("Heinrich-Ritzel-Straße");
		break;
	}
	case 1245:
	{
		returnValue = F("Heinrich-Schmidt-Straße");
		break;
	}
	case 1246:
	{
		returnValue = F("Heinrich-Will-Straße");
		break;
	}
	case 1247:
	{
		returnValue = F("Helene-Weber-Weg");
		break;
	}
	case 1248:
	{
		returnValue = F("Helenengasse");
		break;
	}
	case 1249:
	{
		returnValue = F("Helenenstraße");
		break;
	}
	case 1250:
	{
		returnValue = F("Helgengärten");
		break;
	}
	case 1251:
	{
		returnValue = F("Helgenstockstraße");
		break;
	}
	case 1252:
	{
		returnValue = F("Helgenwald");
		break;
	}
	case 1253:
	{
		returnValue = F("Helgenwiese");
		break;
	}
	case 1254:
	{
		returnValue = F("Hellasweg");
		break;
	}
	case 1255:
	{
		returnValue = F("Hellenbergstraße");
		break;
	}
	case 1256:
	{
		returnValue = F("Hellengartenweg");
		break;
	}
	case 1257:
	{
		returnValue = F("Hellenweg");
		break;
	}
	case 1258:
	{
		returnValue = F("Hellersberg");
		break;
	}
	case 1259:
	{
		returnValue = F("Hellpfad");
		break;
	}
	case 1260:
	{
		returnValue = F("Henriette-Fürth-Straße");
		break;
	}
	case 1261:
	{
		returnValue = F("Henriette-Hezel-Straße");
		break;
	}
	case 1262:
	{
		returnValue = F("Henry-Dunant-Straße");
		break;
	}
	case 1263:
	{
		returnValue = F("Henselstraße");
		break;
	}
	case 1264:
	{
		returnValue = F("Herderstraße");
		break;
	}
	case 1265:
	{
		returnValue = F("Herderweg");
		break;
	}
	case 1266:
	{
		returnValue = F("Hermann-Levi-Straße");
		break;
	}
	case 1267:
	{
		returnValue = F("Hermann-Löns-Straße");
		break;
	}
	case 1268:
	{
		returnValue = F("Hermann-Löns-Weg");
		break;
	}
	case 1269:
	{
		returnValue = F("Hermann-Rau-Straße");
		break;
	}
	case 1270:
	{
		returnValue = F("Hermannsgarten");
		break;
	}
	case 1271:
	{
		returnValue = F("Hermesdorfer Straße");
		break;
	}
	case 1272:
	{
		returnValue = F("Herrenhausgasse");
		break;
	}
	case 1273:
	{
		returnValue = F("Herrenweg");
		break;
	}
	case 1274:
	{
		returnValue = F("Herrngarten");
		break;
	}
	case 1275:
	{
		returnValue = F("Herrnstraße");
		break;
	}
	case 1276:
	{
		returnValue = F("Hessenbrückenhammer");
		break;
	}
	case 1277:
	{
		returnValue = F("Hessenbrückenhof");
		break;
	}
	case 1278:
	{
		returnValue = F("Hessenbrückenmühle");
		break;
	}
	case 1279:
	{
		returnValue = F("Hessenburg");
		break;
	}
	case 1280:
	{
		returnValue = F("Hessengasse");
		break;
	}
	case 1281:
	{
		returnValue = F("Hessenstraße");
		break;
	}
	case 1282:
	{
		returnValue = F("Heuchelheimer Straße");
		break;
	}
	case 1283:
	{
		returnValue = F("Heugärtenweg");
		break;
	}
	case 1284:
	{
		returnValue = F("Hexenweg");
		break;
	}
	case 1285:
	{
		returnValue = F("Heyerweg");
		break;
	}
	case 1286:
	{
		returnValue = F("Hiesbach");
		break;
	}
	case 1287:
	{
		returnValue = F("Hildegard-von-Bingen-Straße");
		break;
	}
	case 1288:
	{
		returnValue = F("Hillebrandstraße");
		break;
	}
	case 1289:
	{
		returnValue = F("Himbergstraße");
		break;
	}
	case 1290:
	{
		returnValue = F("Hindemithstraße");
		break;
	}
	case 1291:
	{
		returnValue = F("Hindenburgstraße");
		break;
	}
	case 1292:
	{
		returnValue = F("Hinkelsweg");
		break;
	}
	case 1293:
	{
		returnValue = F("Hinter dem Brauhaus");
		break;
	}
	case 1294:
	{
		returnValue = F("Hinter dem Dorf");
		break;
	}
	case 1295:
	{
		returnValue = F("Hinter dem Hof");
		break;
	}
	case 1296:
	{
		returnValue = F("Hinter dem Niederhofen");
		break;
	}
	case 1297:
	{
		returnValue = F("Hinter dem Rathaus");
		break;
	}
	case 1298:
	{
		returnValue = F("Hinter dem Sportplatz");
		break;
	}
	case 1299:
	{
		returnValue = F("Hinter dem Steinrücken");
		break;
	}
	case 1300:
	{
		returnValue = F("Hinter den Gärten");
		break;
	}
	case 1301:
	{
		returnValue = F("Hinter der Ahornstraße");
		break;
	}
	case 1302:
	{
		returnValue = F("Hinter der Herberge");
		break;
	}
	case 1303:
	{
		returnValue = F("Hinter der Kirche");
		break;
	}
	case 1304:
	{
		returnValue = F("Hinter der Kleinmühle");
		break;
	}
	case 1305:
	{
		returnValue = F("Hinter der Linde");
		break;
	}
	case 1306:
	{
		returnValue = F("Hinter der Mühle");
		break;
	}
	case 1307:
	{
		returnValue = F("Hinter der Ostanlage");
		break;
	}
	case 1308:
	{
		returnValue = F("Hinter der Platte");
		break;
	}
	case 1309:
	{
		returnValue = F("Hinter der Westanlage");
		break;
	}
	case 1310:
	{
		returnValue = F("Hinterdorf");
		break;
	}
	case 1311:
	{
		returnValue = F("Hinterecke");
		break;
	}
	case 1312:
	{
		returnValue = F("Hintergasse");
		break;
	}
	case 1313:
	{
		returnValue = F("Hinterm Eulenring");
		break;
	}
	case 1314:
	{
		returnValue = F("Hinterm Turm");
		break;
	}
	case 1315:
	{
		returnValue = F("Hirschborner Hof");
		break;
	}
	case 1316:
	{
		returnValue = F("Hirschpfad");
		break;
	}
	case 1317:
	{
		returnValue = F("Hirschsprung");
		break;
	}
	case 1318:
	{
		returnValue = F("Hirtenweg");
		break;
	}
	case 1319:
	{
		returnValue = F("Hochelheimer Weg");
		break;
	}
	case 1320:
	{
		returnValue = F("Hochstraße");
		break;
	}
	case 1321:
	{
		returnValue = F("Hochwarte");
		break;
	}
	case 1322:
	{
		returnValue = F("Höfeweg");
		break;
	}
	case 1323:
	{
		returnValue = F("Höhenstraße");
		break;
	}
	case 1324:
	{
		returnValue = F("Höhenweg");
		break;
	}
	case 1325:
	{
		returnValue = F("Höhlerstraße");
		break;
	}
	case 1326:
	{
		returnValue = F("Hölderlinstraße");
		break;
	}
	case 1327:
	{
		returnValue = F("Hölderlinweg");
		break;
	}
	case 1328:
	{
		returnValue = F("Höllenbachstraße");
		break;
	}
	case 1329:
	{
		returnValue = F("Hölzchesweg");
		break;
	}
	case 1330:
	{
		returnValue = F("Höres Mühle");
		break;
	}
	case 1331:
	{
		returnValue = F("Hörnsheimer Straße");
		break;
	}
	case 1332:
	{
		returnValue = F("Hof-Güller-Straße");
		break;
	}
	case 1333:
	{
		returnValue = F("Hof Bingel");
		break;
	}
	case 1334:
	{
		returnValue = F("Hof Graß");
		break;
	}
	case 1335:
	{
		returnValue = F("Hof Güll");
		break;
	}
	case 1336:
	{
		returnValue = F("Hof Haina");
		break;
	}
	case 1337:
	{
		returnValue = F("Hof Jagdhaus");
		break;
	}
	case 1338:
	{
		returnValue = F("Hof Klotz");
		break;
	}
	case 1339:
	{
		returnValue = F("Hof Konrad");
		break;
	}
	case 1340:
	{
		returnValue = F("Hof Laux");
		break;
	}
	case 1341:
	{
		returnValue = F("Hof Moritzburg");
		break;
	}
	case 1342:
	{
		returnValue = F("Hof Mühlsachsen");
		break;
	}
	case 1343:
	{
		returnValue = F("Hof Niederfeld");
		break;
	}
	case 1344:
	{
		returnValue = F("Hof Obersteinberg");
		break;
	}
	case 1345:
	{
		returnValue = F("Hof Schmitte");
		break;
	}
	case 1346:
	{
		returnValue = F("Hof Struppbach");
		break;
	}
	case 1347:
	{
		returnValue = F("Hof Wiesental");
		break;
	}
	case 1348:
	{
		returnValue = F("Hofacker");
		break;
	}
	case 1349:
	{
		returnValue = F("Hofackerstraße");
		break;
	}
	case 1350:
	{
		returnValue = F("Hofackerweg");
		break;
	}
	case 1351:
	{
		returnValue = F("Hofäckerweg");
		break;
	}
	case 1352:
	{
		returnValue = F("Hofburgstraße");
		break;
	}
	case 1353:
	{
		returnValue = F("Hofdrieschweg");
		break;
	}
	case 1354:
	{
		returnValue = F("Hoffmannstraße");
		break;
	}
	case 1355:
	{
		returnValue = F("Hofgärten");
		break;
	}
	case 1356:
	{
		returnValue = F("Hofgartenstraße");
		break;
	}
	case 1357:
	{
		returnValue = F("Hofgut Albach");
		break;
	}
	case 1358:
	{
		returnValue = F("Hofgut Appenborn");
		break;
	}
	case 1359:
	{
		returnValue = F("Hofgut Friedelhausen");
		break;
	}
	case 1360:
	{
		returnValue = F("Hofgut Kolnhausen");
		break;
	}
	case 1361:
	{
		returnValue = F("Hofgut Ringelshausen");
		break;
	}
	case 1362:
	{
		returnValue = F("Hofgut Winnerod");
		break;
	}
	case 1363:
	{
		returnValue = F("Hofmannstraße");
		break;
	}
	case 1364:
	{
		returnValue = F("Hofstatt");
		break;
	}
	case 1365:
	{
		returnValue = F("Hofstraße");
		break;
	}
	case 1366:
	{
		returnValue = F("Hofwiesenstraße");
		break;
	}
	case 1367:
	{
		returnValue = F("Hohe Buche");
		break;
	}
	case 1368:
	{
		returnValue = F("Hohensolmser Weg");
		break;
	}
	case 1369:
	{
		returnValue = F("Hohensteinring");
		break;
	}
	case 1370:
	{
		returnValue = F("Hoher Rain");
		break;
	}
	case 1371:
	{
		returnValue = F("Hohl");
		break;
	}
	case 1372:
	{
		returnValue = F("Hohler Weg");
		break;
	}
	case 1373:
	{
		returnValue = F("Hohlgärten");
		break;
	}
	case 1374:
	{
		returnValue = F("Hohlgarten");
		break;
	}
	case 1375:
	{
		returnValue = F("Hohlgraben");
		break;
	}
	case 1376:
	{
		returnValue = F("Hohlstraße");
		break;
	}
	case 1377:
	{
		returnValue = F("Hohlweg");
		break;
	}
	case 1378:
	{
		returnValue = F("Holbeinring");
		break;
	}
	case 1379:
	{
		returnValue = F("Hollerstrauch");
		break;
	}
	case 1380:
	{
		returnValue = F("Hollerweg");
		break;
	}
	case 1381:
	{
		returnValue = F("Holunderweg");
		break;
	}
	case 1382:
	{
		returnValue = F("Holzberg");
		break;
	}
	case 1383:
	{
		returnValue = F("Holzbrückenweg");
		break;
	}
	case 1384:
	{
		returnValue = F("Holzheimer Hof");
		break;
	}
	case 1385:
	{
		returnValue = F("Holzheimer Straße");
		break;
	}
	case 1386:
	{
		returnValue = F("Holzheimer Weg");
		break;
	}
	case 1387:
	{
		returnValue = F("Holzmühler Weg");
		break;
	}
	case 1388:
	{
		returnValue = F("Holzpfad");
		break;
	}
	case 1389:
	{
		returnValue = F("Holzweg");
		break;
	}
	case 1390:
	{
		returnValue = F("Homberger Straße");
		break;
	}
	case 1391:
	{
		returnValue = F("Hombergstraße");
		break;
	}
	case 1392:
	{
		returnValue = F("Honzgasse");
		break;
	}
	case 1393:
	{
		returnValue = F("Hopfenacker");
		break;
	}
	case 1394:
	{
		returnValue = F("Hopfengärten");
		break;
	}
	case 1395:
	{
		returnValue = F("Hopfengarten");
		break;
	}
	case 1396:
	{
		returnValue = F("Hoppensteinstraße");
		break;
	}
	case 1397:
	{
		returnValue = F("Horloffstraße");
		break;
	}
	case 1398:
	{
		returnValue = F("Horlofftalstraße");
		break;
	}
	case 1399:
	{
		returnValue = F("Hornackerring");
		break;
	}
	case 1400:
	{
		returnValue = F("Hubertusstraße");
		break;
	}
	case 1401:
	{
		returnValue = F("Hüblerweg");
		break;
	}
	case 1402:
	{
		returnValue = F("Hügelstraße");
		break;
	}
	case 1403:
	{
		returnValue = F("Hüttenbach");
		break;
	}
	case 1404:
	{
		returnValue = F("Hüttenberger Straße");
		break;
	}
	case 1405:
	{
		returnValue = F("Hüttenbergstraße");
		break;
	}
	case 1406:
	{
		returnValue = F("Hüttengasse");
		break;
	}
	case 1407:
	{
		returnValue = F("Hüttenweg");
		break;
	}
	case 1408:
	{
		returnValue = F("Hugo-von-Ritgen-Straße");
		break;
	}
	case 1409:
	{
		returnValue = F("Hultschiner Straße");
		break;
	}
	case 1410:
	{
		returnValue = F("Humboldtring");
		break;
	}
	case 1411:
	{
		returnValue = F("Humboldtstraße");
		break;
	}
	case 1412:
	{
		returnValue = F("Hundsgasse");
		break;
	}
	case 1413:
	{
		returnValue = F("Hunfeld");
		break;
	}
	case 1414:
	{
		returnValue = F("Hungener Pforte");
		break;
	}
	case 1415:
	{
		returnValue = F("Hungener Straße");
		break;
	}
	case 1416:
	{
		returnValue = F("Hungener Weg");
		break;
	}
	case 1417:
	{
		returnValue = F("Iheringstraße");
		break;
	}
	case 1418:
	{
		returnValue = F("Ilsdorfer Straße");
		break;
	}
	case 1419:
	{
		returnValue = F("Im Alten Hof");
		break;
	}
	case 1420:
	{
		returnValue = F("Im Alten Posthof");
		break;
	}
	case 1421:
	{
		returnValue = F("Im Backenborn");
		break;
	}
	case 1422:
	{
		returnValue = F("Im Baumgarten");
		break;
	}
	case 1423:
	{
		returnValue = F("Im Boden");
		break;
	}
	case 1424:
	{
		returnValue = F("Im Bornfeld");
		break;
	}
	case 1425:
	{
		returnValue = F("Im Brühl");
		break;
	}
	case 1426:
	{
		returnValue = F("Im Brühlhof");
		break;
	}
	case 1427:
	{
		returnValue = F("Im Burggarten");
		break;
	}
	case 1428:
	{
		returnValue = F("Im Eckengarten");
		break;
	}
	case 1429:
	{
		returnValue = F("Im Esp");
		break;
	}
	case 1430:
	{
		returnValue = F("Im Eulersgrund");
		break;
	}
	case 1431:
	{
		returnValue = F("Im Feldchen");
		break;
	}
	case 1432:
	{
		returnValue = F("Im Gässchen");
		break;
	}
	case 1433:
	{
		returnValue = F("Im Greben");
		break;
	}
	case 1434:
	{
		returnValue = F("Im Grünen Grund");
		break;
	}
	case 1435:
	{
		returnValue = F("Im Grund");
		break;
	}
	case 1436:
	{
		returnValue = F("Im Hain");
		break;
	}
	case 1437:
	{
		returnValue = F("Im Hansisgarten");
		break;
	}
	case 1438:
	{
		returnValue = F("Im Herrengarten");
		break;
	}
	case 1439:
	{
		returnValue = F("Im Himmerich");
		break;
	}
	case 1440:
	{
		returnValue = F("Im Hofgarten");
		break;
	}
	case 1441:
	{
		returnValue = F("Im Hopfengarten");
		break;
	}
	case 1442:
	{
		returnValue = F("Im Junkerngarten");
		break;
	}
	case 1443:
	{
		returnValue = F("Im Kaisersgrund");
		break;
	}
	case 1444:
	{
		returnValue = F("Im Kalten Grund");
		break;
	}
	case 1445:
	{
		returnValue = F("Im Katzengraben");
		break;
	}
	case 1446:
	{
		returnValue = F("Im Keul");
		break;
	}
	case 1447:
	{
		returnValue = F("Im Kirchboden");
		break;
	}
	case 1448:
	{
		returnValue = F("Im Kleefeld");
		break;
	}
	case 1449:
	{
		returnValue = F("Im Kleegarten");
		break;
	}
	case 1450:
	{
		returnValue = F("Im Kunfe");
		break;
	}
	case 1451:
	{
		returnValue = F("Im Leuchel");
		break;
	}
	case 1452:
	{
		returnValue = F("Im Lindenstück");
		break;
	}
	case 1453:
	{
		returnValue = F("Im Linn");
		break;
	}
	case 1454:
	{
		returnValue = F("Im Löchel");
		break;
	}
	case 1455:
	{
		returnValue = F("Im Möhrengarten");
		break;
	}
	case 1456:
	{
		returnValue = F("Im Mühlfeld");
		break;
	}
	case 1457:
	{
		returnValue = F("Im Niederfeld");
		break;
	}
	case 1458:
	{
		returnValue = F("Im Noll");
		break;
	}
	case 1459:
	{
		returnValue = F("Im Nordpark");
		break;
	}
	case 1460:
	{
		returnValue = F("Im Ostpark");
		break;
	}
	case 1461:
	{
		returnValue = F("Im Pfeilersgarten");
		break;
	}
	case 1462:
	{
		returnValue = F("Im Schacht");
		break;
	}
	case 1463:
	{
		returnValue = F("Im Senser");
		break;
	}
	case 1464:
	{
		returnValue = F("Im Sporn");
		break;
	}
	case 1465:
	{
		returnValue = F("Im Steingarten");
		break;
	}
	case 1466:
	{
		returnValue = F("Im Uderborn");
		break;
	}
	case 1467:
	{
		returnValue = F("Im Vogelsang");
		break;
	}
	case 1468:
	{
		returnValue = F("Im Wäldchen");
		break;
	}
	case 1469:
	{
		returnValue = F("Im Westerfeld");
		break;
	}
	case 1470:
	{
		returnValue = F("Im Westpark");
		break;
	}
	case 1471:
	{
		returnValue = F("Im Wickengarten");
		break;
	}
	case 1472:
	{
		returnValue = F("Im Wiesgarten");
		break;
	}
	case 1473:
	{
		returnValue = F("Im Winkel");
		break;
	}
	case 1474:
	{
		returnValue = F("In den Bachgärten");
		break;
	}
	case 1475:
	{
		returnValue = F("In den Borngärten");
		break;
	}
	case 1476:
	{
		returnValue = F("In den Bruchwiesen");
		break;
	}
	case 1477:
	{
		returnValue = F("In den Erlen");
		break;
	}
	case 1478:
	{
		returnValue = F("In den Gärten");
		break;
	}
	case 1479:
	{
		returnValue = F("In den Gensäckern");
		break;
	}
	case 1480:
	{
		returnValue = F("In den Gossegärten");
		break;
	}
	case 1481:
	{
		returnValue = F("In den Gräben");
		break;
	}
	case 1482:
	{
		returnValue = F("In den Haingärten");
		break;
	}
	case 1483:
	{
		returnValue = F("In den Hardtberggärten");
		break;
	}
	case 1484:
	{
		returnValue = F("In den Höfen");
		break;
	}
	case 1485:
	{
		returnValue = F("In den Kleewiesen");
		break;
	}
	case 1486:
	{
		returnValue = F("In den Klostergärten");
		break;
	}
	case 1487:
	{
		returnValue = F("In den Musgärten");
		break;
	}
	case 1488:
	{
		returnValue = F("In den Obergärten");
		break;
	}
	case 1489:
	{
		returnValue = F("In den Petersgärten");
		break;
	}
	case 1490:
	{
		returnValue = F("In den Rechtenwiesen");
		break;
	}
	case 1491:
	{
		returnValue = F("In den Riebäckern");
		break;
	}
	case 1492:
	{
		returnValue = F("In den Rödern");
		break;
	}
	case 1493:
	{
		returnValue = F("In den Röderwiesen");
		break;
	}
	case 1494:
	{
		returnValue = F("In den Schrebergärten");
		break;
	}
	case 1495:
	{
		returnValue = F("In den Seifenwiesen");
		break;
	}
	case 1496:
	{
		returnValue = F("In den Weingärten");
		break;
	}
	case 1497:
	{
		returnValue = F("In den Zaungärten");
		break;
	}
	case 1498:
	{
		returnValue = F("In den Zwirnäcker");
		break;
	}
	case 1499:
	{
		returnValue = F("In der Au");
		break;
	}
	case 1500:
	{
		returnValue = F("In der Bette");
		break;
	}
	case 1501:
	{
		returnValue = F("In der Bettwiese");
		break;
	}
	case 1502:
	{
		returnValue = F("In der Beune");
		break;
	}
	case 1503:
	{
		returnValue = F("In der Eck");
		break;
	}
	case 1504:
	{
		returnValue = F("In der Ecke");
		break;
	}
	case 1505:
	{
		returnValue = F("In der Gombach");
		break;
	}
	case 1506:
	{
		returnValue = F("In der Grube");
		break;
	}
	case 1507:
	{
		returnValue = F("In der Hude");
		break;
	}
	case 1508:
	{
		returnValue = F("In der Hunsbach");
		break;
	}
	case 1509:
	{
		returnValue = F("In der Imsbach");
		break;
	}
	case 1510:
	{
		returnValue = F("In der Lache");
		break;
	}
	case 1511:
	{
		returnValue = F("In der Lautenbach");
		break;
	}
	case 1512:
	{
		returnValue = F("In der Lechenau");
		break;
	}
	case 1513:
	{
		returnValue = F("In der Rehbach");
		break;
	}
	case 1514:
	{
		returnValue = F("In der Roos");
		break;
	}
	case 1515:
	{
		returnValue = F("In der Ruppertsbach");
		break;
	}
	case 1516:
	{
		returnValue = F("In der Steinbach");
		break;
	}
	case 1517:
	{
		returnValue = F("In der Steinwiese");
		break;
	}
	case 1518:
	{
		returnValue = F("In der Wann");
		break;
	}
	case 1519:
	{
		returnValue = F("In der Wiese");
		break;
	}
	case 1520:
	{
		returnValue = F("Industriestraße");
		break;
	}
	case 1521:
	{
		returnValue = F("Inselstraße");
		break;
	}
	case 1522:
	{
		returnValue = F("Inselweg");
		break;
	}
	case 1523:
	{
		returnValue = F("Inwerkstraße");
		break;
	}
	case 1524:
	{
		returnValue = F("Irisweg");
		break;
	}
	case 1525:
	{
		returnValue = F("Jacksonstraße");
		break;
	}
	case 1526:
	{
		returnValue = F("Jägergasse");
		break;
	}
	case 1527:
	{
		returnValue = F("Jägerhaus");
		break;
	}
	case 1528:
	{
		returnValue = F("Jägerhausstraße");
		break;
	}
	case 1529:
	{
		returnValue = F("Jägerpfad");
		break;
	}
	case 1530:
	{
		returnValue = F("Jägerschneise");
		break;
	}
	case 1531:
	{
		returnValue = F("Jagdhütte");
		break;
	}
	case 1532:
	{
		returnValue = F("Jahnstraße");
		break;
	}
	case 1533:
	{
		returnValue = F("Jahnweg");
		break;
	}
	case 1534:
	{
		returnValue = F("Jakob-Uhrhan-Straße");
		break;
	}
	case 1535:
	{
		returnValue = F("Jakobsweg");
		break;
	}
	case 1536:
	{
		returnValue = F("Jasminweg");
		break;
	}
	case 1537:
	{
		returnValue = F("Jefferson Street");
		break;
	}
	case 1538:
	{
		returnValue = F("Jenaer Straße");
		break;
	}
	case 1539:
	{
		returnValue = F("Joachimstaler Straße");
		break;
	}
	case 1540:
	{
		returnValue = F("Johann-Bernhard-Wilbrand-Straße");
		break;
	}
	case 1541:
	{
		returnValue = F("Johann-Georg-Will-Straße");
		break;
	}
	case 1542:
	{
		returnValue = F("Johann-Sebastian-Bach-Straße");
		break;
	}
	case 1543:
	{
		returnValue = F("Johann-Strauß-Straße");
		break;
	}
	case 1544:
	{
		returnValue = F("Johannes-Calvin-Straße");
		break;
	}
	case 1545:
	{
		returnValue = F("Johannes-Heß-Straße");
		break;
	}
	case 1546:
	{
		returnValue = F("Johannes-Leun-Straße");
		break;
	}
	case 1547:
	{
		returnValue = F("Johannes-Rau-Straße");
		break;
	}
	case 1548:
	{
		returnValue = F("Johannesbader Straße");
		break;
	}
	case 1549:
	{
		returnValue = F("Johannesberg");
		break;
	}
	case 1550:
	{
		returnValue = F("Johanneshof");
		break;
	}
	case 1551:
	{
		returnValue = F("Johannesstraße");
		break;
	}
	case 1552:
	{
		returnValue = F("Johannette-Lein-Gasse");
		break;
	}
	case 1553:
	{
		returnValue = F("Johanniterplatz");
		break;
	}
	case 1554:
	{
		returnValue = F("John-F.-Kennedy-Platz");
		break;
	}
	case 1555:
	{
		returnValue = F("Joseph-Haydn-Straße");
		break;
	}
	case 1556:
	{
		returnValue = F("Joseph-Kreuter-Weg");
		break;
	}
	case 1557:
	{
		returnValue = F("Judengasse");
		break;
	}
	case 1558:
	{
		returnValue = F("Julius-Höpfner-Straße");
		break;
	}
	case 1559:
	{
		returnValue = F("Jungfernstraße");
		break;
	}
	case 1560:
	{
		returnValue = F("Junggartenstraße");
		break;
	}
	case 1561:
	{
		returnValue = F("Junkergarten");
		break;
	}
	case 1562:
	{
		returnValue = F("Junkergasse");
		break;
	}
	case 1563:
	{
		returnValue = F("Junkermühle");
		break;
	}
	case 1564:
	{
		returnValue = F("Junkernstraße");
		break;
	}
	case 1565:
	{
		returnValue = F("Junkersstraße");
		break;
	}
	case 1566:
	{
		returnValue = F("Justus-Kilian-Straße");
		break;
	}
	case 1567:
	{
		returnValue = F("Justusstraße");
		break;
	}
	case 1568:
	{
		returnValue = F("Kälbergasse");
		break;
	}
	case 1569:
	{
		returnValue = F("Käthe-Kollwitz-Straße");
		break;
	}
	case 1570:
	{
		returnValue = F("Kättergrund");
		break;
	}
	case 1571:
	{
		returnValue = F("Kahlweg");
		break;
	}
	case 1572:
	{
		returnValue = F("Kaiserstraße");
		break;
	}
	case 1573:
	{
		returnValue = F("Kalkweg");
		break;
	}
	case 1574:
	{
		returnValue = F("Kaltenrainstraße");
		break;
	}
	case 1575:
	{
		returnValue = F("Kammerfeld");
		break;
	}
	case 1576:
	{
		returnValue = F("Kammergasse");
		break;
	}
	case 1577:
	{
		returnValue = F("Kaninchenpfad");
		break;
	}
	case 1578:
	{
		returnValue = F("Kantstraße");
		break;
	}
	case 1579:
	{
		returnValue = F("Kanzleiberg");
		break;
	}
	case 1580:
	{
		returnValue = F("Kapellenstraße");
		break;
	}
	case 1581:
	{
		returnValue = F("Kaplansgasse");
		break;
	}
	case 1582:
	{
		returnValue = F("Karl-Benner-Straße");
		break;
	}
	case 1583:
	{
		returnValue = F("Karl-Benz-Straße");
		break;
	}
	case 1584:
	{
		returnValue = F("Karl-Engel-Straße");
		break;
	}
	case 1585:
	{
		returnValue = F("Karl-Follen-Straße");
		break;
	}
	case 1586:
	{
		returnValue = F("Karl-Glöckner-Straße");
		break;
	}
	case 1587:
	{
		returnValue = F("Karl-Keller-Straße");
		break;
	}
	case 1588:
	{
		returnValue = F("Karl-Kling-Straße");
		break;
	}
	case 1589:
	{
		returnValue = F("Karl-Reinhardt-Gasse");
		break;
	}
	case 1590:
	{
		returnValue = F("Karl-Reuter-Weg");
		break;
	}
	case 1591:
	{
		returnValue = F("Karl-Sack-Straße");
		break;
	}
	case 1592:
	{
		returnValue = F("Karlsbader Straße");
		break;
	}
	case 1593:
	{
		returnValue = F("Karlstraße");
		break;
	}
	case 1594:
	{
		returnValue = F("Kasseler Straße");
		break;
	}
	case 1595:
	{
		returnValue = F("Kastanienweg");
		break;
	}
	case 1596:
	{
		returnValue = F("Kastellstraße");
		break;
	}
	case 1597:
	{
		returnValue = F("Katergasse");
		break;
	}
	case 1598:
	{
		returnValue = F("Katharinengasse");
		break;
	}
	case 1599:
	{
		returnValue = F("Katharinenplatz");
		break;
	}
	case 1600:
	{
		returnValue = F("Katharinenstraße");
		break;
	}
	case 1601:
	{
		returnValue = F("Kattenbachstraße");
		break;
	}
	case 1602:
	{
		returnValue = F("Katzenbach");
		break;
	}
	case 1603:
	{
		returnValue = F("Kegelbahn");
		break;
	}
	case 1604:
	{
		returnValue = F("Kehlbachstraße");
		break;
	}
	case 1605:
	{
		returnValue = F("Keilerweg");
		break;
	}
	case 1606:
	{
		returnValue = F("Keilstraße");
		break;
	}
	case 1607:
	{
		returnValue = F("Kellereigasse");
		break;
	}
	case 1608:
	{
		returnValue = F("Kellersgärten");
		break;
	}
	case 1609:
	{
		returnValue = F("Kellersmühle");
		break;
	}
	case 1610:
	{
		returnValue = F("Keltenweg");
		break;
	}
	case 1611:
	{
		returnValue = F("Keplerstraße");
		break;
	}
	case 1612:
	{
		returnValue = F("Kerkrader Straße");
		break;
	}
	case 1613:
	{
		returnValue = F("Kernstraße");
		break;
	}
	case 1614:
	{
		returnValue = F("Kesslerstraße");
		break;
	}
	case 1615:
	{
		returnValue = F("Kiebitzweg");
		break;
	}
	case 1616:
	{
		returnValue = F("Kiefernring");
		break;
	}
	case 1617:
	{
		returnValue = F("Kiefernweg");
		break;
	}
	case 1618:
	{
		returnValue = F("Kieferstädteler Straße");
		break;
	}
	case 1619:
	{
		returnValue = F("Kiesacker");
		break;
	}
	case 1620:
	{
		returnValue = F("Kieselgurweg");
		break;
	}
	case 1621:
	{
		returnValue = F("Kieselweg");
		break;
	}
	case 1622:
	{
		returnValue = F("Kiesweg");
		break;
	}
	case 1623:
	{
		returnValue = F("Kindergartenstraße");
		break;
	}
	case 1624:
	{
		returnValue = F("Kindergartenweg");
		break;
	}
	case 1625:
	{
		returnValue = F("Kinzenbacher Mühle");
		break;
	}
	case 1626:
	{
		returnValue = F("Kinzenbacher Straße");
		break;
	}
	case 1627:
	{
		returnValue = F("Kirchberg");
		break;
	}
	case 1628:
	{
		returnValue = F("Kirchberger Weg");
		break;
	}
	case 1629:
	{
		returnValue = F("Kirchbergstraße");
		break;
	}
	case 1630:
	{
		returnValue = F("Kirchenplatz");
		break;
	}
	case 1631:
	{
		returnValue = F("Kirchenring");
		break;
	}
	case 1632:
	{
		returnValue = F("Kirchgärten");
		break;
	}
	case 1633:
	{
		returnValue = F("Kirchgässchen");
		break;
	}
	case 1634:
	{
		returnValue = F("Kirchgasse");
		break;
	}
	case 1635:
	{
		returnValue = F("Kirchhofgasse");
		break;
	}
	case 1636:
	{
		returnValue = F("Kirchhofstraße");
		break;
	}
	case 1637:
	{
		returnValue = F("Kirchpfad");
		break;
	}
	case 1638:
	{
		returnValue = F("Kirchplatz");
		break;
	}
	case 1639:
	{
		returnValue = F("Kirchstraße");
		break;
	}
	case 1640:
	{
		returnValue = F("Kirchweg");
		break;
	}
	case 1641:
	{
		returnValue = F("Kirlenring");
		break;
	}
	case 1642:
	{
		returnValue = F("Kirschbaumweg");
		break;
	}
	case 1643:
	{
		returnValue = F("Kirschbergstraße");
		break;
	}
	case 1644:
	{
		returnValue = F("Kirschenberg");
		break;
	}
	case 1645:
	{
		returnValue = F("Kirschenweg");
		break;
	}
	case 1646:
	{
		returnValue = F("Kirschgarten");
		break;
	}
	case 1647:
	{
		returnValue = F("Kirschweg");
		break;
	}
	case 1648:
	{
		returnValue = F("Kisselweg");
		break;
	}
	case 1649:
	{
		returnValue = F("Klausegasse");
		break;
	}
	case 1650:
	{
		returnValue = F("Klausenberg");
		break;
	}
	case 1651:
	{
		returnValue = F("Klausenweg");
		break;
	}
	case 1652:
	{
		returnValue = F("Kleebachstraße");
		break;
	}
	case 1653:
	{
		returnValue = F("Kleebergstraße");
		break;
	}
	case 1654:
	{
		returnValue = F("Kleebrunnenstraße");
		break;
	}
	case 1655:
	{
		returnValue = F("Kleegarten");
		break;
	}
	case 1656:
	{
		returnValue = F("Kleegasse");
		break;
	}
	case 1657:
	{
		returnValue = F("Kleehofstraße");
		break;
	}
	case 1658:
	{
		returnValue = F("Kleeweg");
		break;
	}
	case 1659:
	{
		returnValue = F("Kleewiesenweg");
		break;
	}
	case 1660:
	{
		returnValue = F("Kleine Gasse");
		break;
	}
	case 1661:
	{
		returnValue = F("Kleine Mühlgasse");
		break;
	}
	case 1662:
	{
		returnValue = F("Kleiner Ring");
		break;
	}
	case 1663:
	{
		returnValue = F("Kleinfeldchen");
		break;
	}
	case 1664:
	{
		returnValue = F("Kleinlindener Straße");
		break;
	}
	case 1665:
	{
		returnValue = F("Kleinmühle");
		break;
	}
	case 1666:
	{
		returnValue = F("Kleiststraße");
		break;
	}
	case 1667:
	{
		returnValue = F("Klingelbachweg");
		break;
	}
	case 1668:
	{
		returnValue = F("Klingelgarten");
		break;
	}
	case 1669:
	{
		returnValue = F("Klinikstraße");
		break;
	}
	case 1670:
	{
		returnValue = F("Klossengasse");
		break;
	}
	case 1671:
	{
		returnValue = F("Kloster Arnsburg");
		break;
	}
	case 1672:
	{
		returnValue = F("Klostergasse");
		break;
	}
	case 1673:
	{
		returnValue = F("Klosterpfad");
		break;
	}
	case 1674:
	{
		returnValue = F("Klosterwald");
		break;
	}
	case 1675:
	{
		returnValue = F("Klosterweg");
		break;
	}
	case 1676:
	{
		returnValue = F("Knorrhof");
		break;
	}
	case 1677:
	{
		returnValue = F("Köhlerweg");
		break;
	}
	case 1678:
	{
		returnValue = F("Köllersgarten");
		break;
	}
	case 1679:
	{
		returnValue = F("Königgrätzer Straße");
		break;
	}
	case 1680:
	{
		returnValue = F("Königsberger Straße");
		break;
	}
	case 1681:
	{
		returnValue = F("Köppelweg");
		break;
	}
	case 1682:
	{
		returnValue = F("Kösliner Straße");
		break;
	}
	case 1683:
	{
		returnValue = F("Köstweg");
		break;
	}
	case 1684:
	{
		returnValue = F("Kohlgasse");
		break;
	}
	case 1685:
	{
		returnValue = F("Kohlweg");
		break;
	}
	case 1686:
	{
		returnValue = F("Kolbenmühle");
		break;
	}
	case 1687:
	{
		returnValue = F("Kolberger Straße");
		break;
	}
	case 1688:
	{
		returnValue = F("Kolnhäuser Hof");
		break;
	}
	case 1689:
	{
		returnValue = F("Kolnhäuser Straße");
		break;
	}
	case 1690:
	{
		returnValue = F("Kolpingstraße");
		break;
	}
	case 1691:
	{
		returnValue = F("Kommenturgasse");
		break;
	}
	case 1692:
	{
		returnValue = F("Konrad-Adenauer-Straße");
		break;
	}
	case 1693:
	{
		returnValue = F("Konrad-Henrich-Straße");
		break;
	}
	case 1694:
	{
		returnValue = F("Konrad-Zuse-Straße");
		break;
	}
	case 1695:
	{
		returnValue = F("Konstantinbader Straße");
		break;
	}
	case 1696:
	{
		returnValue = F("Konzebühler Hof");
		break;
	}
	case 1697:
	{
		returnValue = F("Koordinaten");
		break;
	}
	case 1698:
	{
		returnValue = F("Kopernikusweg");
		break;
	}
	case 1699:
	{
		returnValue = F("Kornblumenstraße");
		break;
	}
	case 1700:
	{
		returnValue = F("Krähenweg");
		break;
	}
	case 1701:
	{
		returnValue = F("Krämersgarten");
		break;
	}
	case 1702:
	{
		returnValue = F("Kranzenberg");
		break;
	}
	case 1703:
	{
		returnValue = F("Krautgarten");
		break;
	}
	case 1704:
	{
		returnValue = F("Krebenweg");
		break;
	}
	case 1705:
	{
		returnValue = F("Kreisstraße");
		break;
	}
	case 1706:
	{
		returnValue = F("Kreuzgasse");
		break;
	}
	case 1707:
	{
		returnValue = F("Kreuzholz");
		break;
	}
	case 1708:
	{
		returnValue = F("Kreuzplatz");
		break;
	}
	case 1709:
	{
		returnValue = F("Kreuzseener Weg");
		break;
	}
	case 1710:
	{
		returnValue = F("Kreuzstraße");
		break;
	}
	case 1711:
	{
		returnValue = F("Kreuzweg");
		break;
	}
	case 1712:
	{
		returnValue = F("Krofdorfer Straße");
		break;
	}
	case 1713:
	{
		returnValue = F("Krokelstraße");
		break;
	}
	case 1714:
	{
		returnValue = F("Kronengasse");
		break;
	}
	case 1715:
	{
		returnValue = F("Kronenhof");
		break;
	}
	case 1716:
	{
		returnValue = F("Kronzenborner Weg");
		break;
	}
	case 1717:
	{
		returnValue = F("Krool");
		break;
	}
	case 1718:
	{
		returnValue = F("Kropbacher Weg");
		break;
	}
	case 1719:
	{
		returnValue = F("Kropbachstraße");
		break;
	}
	case 1720:
	{
		returnValue = F("Krugwiesenweg");
		break;
	}
	case 1721:
	{
		returnValue = F("Krumstück");
		break;
	}
	case 1722:
	{
		returnValue = F("Kuckucksweg");
		break;
	}
	case 1723:
	{
		returnValue = F("Kühnsgasse");
		break;
	}
	case 1724:
	{
		returnValue = F("Kugelberg");
		break;
	}
	case 1725:
	{
		returnValue = F("Kurt-Schumacher-Straße");
		break;
	}
	case 1726:
	{
		returnValue = F("Kurvenstraße");
		break;
	}
	case 1727:
	{
		returnValue = F("Kurze Hohl");
		break;
	}
	case 1728:
	{
		returnValue = F("Lärchenhof");
		break;
	}
	case 1729:
	{
		returnValue = F("Lärchenring");
		break;
	}
	case 1730:
	{
		returnValue = F("Lärchenstraße");
		break;
	}
	case 1731:
	{
		returnValue = F("Lärchenwäldchen");
		break;
	}
	case 1732:
	{
		returnValue = F("Lärchenweg");
		break;
	}
	case 1733:
	{
		returnValue = F("Läufertsröder Weg");
		break;
	}
	case 1734:
	{
		returnValue = F("Lahnparkstraße");
		break;
	}
	case 1735:
	{
		returnValue = F("Lahnstraße");
		break;
	}
	case 1736:
	{
		returnValue = F("Lahnwegsberg");
		break;
	}
	case 1737:
	{
		returnValue = F("Landgraf-Philipp-Platz");
		break;
	}
	case 1738:
	{
		returnValue = F("Landgrafenstraße");
		break;
	}
	case 1739:
	{
		returnValue = F("Landmannstraße");
		break;
	}
	case 1740:
	{
		returnValue = F("Landschulheim Burg Nordeck");
		break;
	}
	case 1741:
	{
		returnValue = F("Landwehrstraße");
		break;
	}
	case 1742:
	{
		returnValue = F("Landwehrweg");
		break;
	}
	case 1743:
	{
		returnValue = F("Langacker");
		break;
	}
	case 1744:
	{
		returnValue = F("Langder Weg");
		break;
	}
	case 1745:
	{
		returnValue = F("Lange Hohl");
		break;
	}
	case 1746:
	{
		returnValue = F("Lange Ortsstraße");
		break;
	}
	case 1747:
	{
		returnValue = F("Langenheckenweg");
		break;
	}
	case 1748:
	{
		returnValue = F("Langer Strich");
		break;
	}
	case 1749:
	{
		returnValue = F("Langer Weg");
		break;
	}
	case 1750:
	{
		returnValue = F("Langerlerhof");
		break;
	}
	case 1751:
	{
		returnValue = F("Langgasse");
		break;
	}
	case 1752:
	{
		returnValue = F("Langgönser Straße");
		break;
	}
	case 1753:
	{
		returnValue = F("Langhansstraße");
		break;
	}
	case 1754:
	{
		returnValue = F("Langsdorfer Straße");
		break;
	}
	case 1755:
	{
		returnValue = F("Langsdorfer Weg");
		break;
	}
	case 1756:
	{
		returnValue = F("Langstraße");
		break;
	}
	case 1757:
	{
		returnValue = F("Lardenbacher Straße");
		break;
	}
	case 1758:
	{
		returnValue = F("Laubacher Straße");
		break;
	}
	case 1759:
	{
		returnValue = F("Laubacher Wald");
		break;
	}
	case 1760:
	{
		returnValue = F("Laubacher Weg");
		break;
	}
	case 1761:
	{
		returnValue = F("Launsbacher Straße");
		break;
	}
	case 1762:
	{
		returnValue = F("Launsbacher Weg");
		break;
	}
	case 1763:
	{
		returnValue = F("Lausköppel");
		break;
	}
	case 1764:
	{
		returnValue = F("Lauterer Straße");
		break;
	}
	case 1765:
	{
		returnValue = F("Lautertalstraße");
		break;
	}
	case 1766:
	{
		returnValue = F("Ledergasse");
		break;
	}
	case 1767:
	{
		returnValue = F("Leerhafer Straße");
		break;
	}
	case 1768:
	{
		returnValue = F("Leestraße");
		break;
	}
	case 1769:
	{
		returnValue = F("Lehmkauter Weg");
		break;
	}
	case 1770:
	{
		returnValue = F("Lehmweg");
		break;
	}
	case 1771:
	{
		returnValue = F("Lehnheimer Weg");
		break;
	}
	case 1772:
	{
		returnValue = F("Leidenhäuser Straße");
		break;
	}
	case 1773:
	{
		returnValue = F("Leihgesterner Straße");
		break;
	}
	case 1774:
	{
		returnValue = F("Leihgesterner Weg");
		break;
	}
	case 1775:
	{
		returnValue = F("Leihgesternerstraße");
		break;
	}
	case 1776:
	{
		returnValue = F("Leimenkauter Weg");
		break;
	}
	case 1777:
	{
		returnValue = F("Leipziger Straße");
		break;
	}
	case 1778:
	{
		returnValue = F("Leppermühle");
		break;
	}
	case 1779:
	{
		returnValue = F("Lerchenstraße");
		break;
	}
	case 1780:
	{
		returnValue = F("Lerchenweg");
		break;
	}
	case 1781:
	{
		returnValue = F("Lessingstraße");
		break;
	}
	case 1782:
	{
		returnValue = F("Licher Berg");
		break;
	}
	case 1783:
	{
		returnValue = F("Licher Pforte");
		break;
	}
	case 1784:
	{
		returnValue = F("Licher Straße");
		break;
	}
	case 1785:
	{
		returnValue = F("Lichtenauer Weg");
		break;
	}
	case 1786:
	{
		returnValue = F("Liebengasse");
		break;
	}
	case 1787:
	{
		returnValue = F("Liebfrauenberg");
		break;
	}
	case 1788:
	{
		returnValue = F("Liebfrauengasse");
		break;
	}
	case 1789:
	{
		returnValue = F("Liebigstraße");
		break;
	}
	case 1790:
	{
		returnValue = F("Lilienstraße");
		break;
	}
	case 1791:
	{
		returnValue = F("Lilienthalstraße");
		break;
	}
	case 1792:
	{
		returnValue = F("Lilienweg");
		break;
	}
	case 1793:
	{
		returnValue = F("Limeshof");
		break;
	}
	case 1794:
	{
		returnValue = F("Limesstraße");
		break;
	}
	case 1795:
	{
		returnValue = F("Lincolnstraße");
		break;
	}
	case 1796:
	{
		returnValue = F("Lindenallee");
		break;
	}
	case 1797:
	{
		returnValue = F("Lindenau");
		break;
	}
	case 1798:
	{
		returnValue = F("Lindengasse");
		break;
	}
	case 1799:
	{
		returnValue = F("Lindenhöfe");
		break;
	}
	case 1800:
	{
		returnValue = F("Lindenhof");
		break;
	}
	case 1801:
	{
		returnValue = F("Lindenplatz");
		break;
	}
	case 1802:
	{
		returnValue = F("Lindenstraße");
		break;
	}
	case 1803:
	{
		returnValue = F("Lindenstruther Weg");
		break;
	}
	case 1804:
	{
		returnValue = F("Lindenweg");
		break;
	}
	case 1805:
	{
		returnValue = F("Linnpfad");
		break;
	}
	case 1806:
	{
		returnValue = F("Linsengasse");
		break;
	}
	case 1807:
	{
		returnValue = F("Linsenweg");
		break;
	}
	case 1808:
	{
		returnValue = F("Lippe");
		break;
	}
	case 1809:
	{
		returnValue = F("Lisztstraße");
		break;
	}
	case 1810:
	{
		returnValue = F("Lobnigstraße");
		break;
	}
	case 1811:
	{
		returnValue = F("Lochermühlsweg");
		break;
	}
	case 1812:
	{
		returnValue = F("Lochweg");
		break;
	}
	case 1813:
	{
		returnValue = F("Löbergasse");
		break;
	}
	case 1814:
	{
		returnValue = F("Löbers Hof");
		break;
	}
	case 1815:
	{
		returnValue = F("Löberstraße");
		break;
	}
	case 1816:
	{
		returnValue = F("Löbsackmühle");
		break;
	}
	case 1817:
	{
		returnValue = F("Löhrbachsgraben");
		break;
	}
	case 1818:
	{
		returnValue = F("Löwengasse");
		break;
	}
	case 1819:
	{
		returnValue = F("Löwenweg");
		break;
	}
	case 1820:
	{
		returnValue = F("Lohkaute");
		break;
	}
	case 1821:
	{
		returnValue = F("Lohwaldstraße");
		break;
	}
	case 1822:
	{
		returnValue = F("Lohweg");
		break;
	}
	case 1823:
	{
		returnValue = F("Lollarer Straße");
		break;
	}
	case 1824:
	{
		returnValue = F("Lollarer Weg");
		break;
	}
	case 1825:
	{
		returnValue = F("Londorfer Straße");
		break;
	}
	case 1826:
	{
		returnValue = F("Lonystraße");
		break;
	}
	case 1827:
	{
		returnValue = F("Louis-Frech-Straße");
		break;
	}
	case 1828:
	{
		returnValue = F("Lucas-Cranach-Straße");
		break;
	}
	case 1829:
	{
		returnValue = F("Ludwig-Dörmer-Straße");
		break;
	}
	case 1830:
	{
		returnValue = F("Ludwig-Erhard-Straße");
		break;
	}
	case 1831:
	{
		returnValue = F("Ludwig-Richter-Straße");
		break;
	}
	case 1832:
	{
		returnValue = F("Ludwig-Rinn-Straße");
		break;
	}
	case 1833:
	{
		returnValue = F("Ludwig-Schneider-Weg");
		break;
	}
	case 1834:
	{
		returnValue = F("Ludwig-Schunk-Straße");
		break;
	}
	case 1835:
	{
		returnValue = F("Ludwig-Seiboldt-Straße");
		break;
	}
	case 1836:
	{
		returnValue = F("Ludwig-Uhland-Straße");
		break;
	}
	case 1837:
	{
		returnValue = F("Ludwig-Weisel-Straße");
		break;
	}
	case 1838:
	{
		returnValue = F("Ludwigsburg");
		break;
	}
	case 1839:
	{
		returnValue = F("Ludwigshof");
		break;
	}
	case 1840:
	{
		returnValue = F("Ludwigsplatz");
		break;
	}
	case 1841:
	{
		returnValue = F("Ludwigstraße");
		break;
	}
	case 1842:
	{
		returnValue = F("Lützelbergstraße");
		break;
	}
	case 1843:
	{
		returnValue = F("Lützellindener Straße");
		break;
	}
	case 1844:
	{
		returnValue = F("Lützelwiesen");
		break;
	}
	case 1845:
	{
		returnValue = F("Lufthansastraße");
		break;
	}
	case 1846:
	{
		returnValue = F("Lugge");
		break;
	}
	case 1847:
	{
		returnValue = F("Lumdagarten");
		break;
	}
	case 1848:
	{
		returnValue = F("Lumdastraße");
		break;
	}
	case 1849:
	{
		returnValue = F("Lumdatalstraße");
		break;
	}
	case 1850:
	{
		returnValue = F("Lupinenweg");
		break;
	}
	case 1851:
	{
		returnValue = F("Lutherberg");
		break;
	}
	case 1852:
	{
		returnValue = F("Lutherstraße");
		break;
	}
	case 1853:
	{
		returnValue = F("Luxemburger Weg");
		break;
	}
	case 1854:
	{
		returnValue = F("Macherenstraße");
		break;
	}
	case 1855:
	{
		returnValue = F("Männchesgasse");
		break;
	}
	case 1856:
	{
		returnValue = F("Mäusburg");
		break;
	}
	case 1857:
	{
		returnValue = F("Magdeburger Straße");
		break;
	}
	case 1858:
	{
		returnValue = F("Mahrweg");
		break;
	}
	case 1859:
	{
		returnValue = F("Maigasse");
		break;
	}
	case 1860:
	{
		returnValue = F("Mailbacher Straße");
		break;
	}
	case 1861:
	{
		returnValue = F("Mainzlarer Straße");
		break;
	}
	case 1862:
	{
		returnValue = F("Mainzlarer Weg");
		break;
	}
	case 1863:
	{
		returnValue = F("Malvenweg");
		break;
	}
	case 1864:
	{
		returnValue = F("Mandlerweg");
		break;
	}
	case 1865:
	{
		returnValue = F("Marburger Straße");
		break;
	}
	case 1866:
	{
		returnValue = F("Margarete-Bieber-Weg");
		break;
	}
	case 1867:
	{
		returnValue = F("Margaretenhütte");
		break;
	}
	case 1868:
	{
		returnValue = F("Margeritenweg");
		break;
	}
	case 1869:
	{
		returnValue = F("Maria-Birnbaum-Weg");
		break;
	}
	case 1870:
	{
		returnValue = F("Mariannenhof");
		break;
	}
	case 1871:
	{
		returnValue = F("Marie-Curie-Weg");
		break;
	}
	case 1872:
	{
		returnValue = F("Marie-Elisabeth-Lüders-Straße");
		break;
	}
	case 1873:
	{
		returnValue = F("Marie-Juchacz-Weg");
		break;
	}
	case 1874:
	{
		returnValue = F("Marienbader Straße");
		break;
	}
	case 1875:
	{
		returnValue = F("Marienbergstraße");
		break;
	}
	case 1876:
	{
		returnValue = F("Marktgasse");
		break;
	}
	case 1877:
	{
		returnValue = F("Marktlaubenstraße");
		break;
	}
	case 1878:
	{
		returnValue = F("Marktplatz");
		break;
	}
	case 1879:
	{
		returnValue = F("Marktstraße");
		break;
	}
	case 1880:
	{
		returnValue = F("Markwald");
		break;
	}
	case 1881:
	{
		returnValue = F("Marschallstraße");
		break;
	}
	case 1882:
	{
		returnValue = F("Marshallstraße");
		break;
	}
	case 1883:
	{
		returnValue = F("Marsteiner Hof");
		break;
	}
	case 1884:
	{
		returnValue = F("Martha-Mendel-Weg");
		break;
	}
	case 1885:
	{
		returnValue = F("Martin-Luther-King-Straße");
		break;
	}
	case 1886:
	{
		returnValue = F("Martin-Luther-Straße");
		break;
	}
	case 1887:
	{
		returnValue = F("Martin-Niemöller-Weg");
		break;
	}
	case 1888:
	{
		returnValue = F("Martinsstraße");
		break;
	}
	case 1889:
	{
		returnValue = F("Max-Eyth-Straße");
		break;
	}
	case 1890:
	{
		returnValue = F("Max-Eyth-Weg");
		break;
	}
	case 1891:
	{
		returnValue = F("Max-Liebermann-Straße");
		break;
	}
	case 1892:
	{
		returnValue = F("Max-Reger-Straße");
		break;
	}
	case 1893:
	{
		returnValue = F("Meerweinstraße");
		break;
	}
	case 1894:
	{
		returnValue = F("Meininger Weg");
		break;
	}
	case 1895:
	{
		returnValue = F("Meisenbornweg");
		break;
	}
	case 1896:
	{
		returnValue = F("Meisenring");
		break;
	}
	case 1897:
	{
		returnValue = F("Meisenweg");
		break;
	}
	case 1898:
	{
		returnValue = F("Meissingerweg");
		break;
	}
	case 1899:
	{
		returnValue = F("Memeler Straße");
		break;
	}
	case 1900:
	{
		returnValue = F("Mengesstraße");
		break;
	}
	case 1901:
	{
		returnValue = F("Menzelstraße");
		break;
	}
	case 1902:
	{
		returnValue = F("Merenberger Straße");
		break;
	}
	case 1903:
	{
		returnValue = F("Messfelder Weg");
		break;
	}
	case 1904:
	{
		returnValue = F("Metzengarten");
		break;
	}
	case 1905:
	{
		returnValue = F("Metzengasse");
		break;
	}
	case 1906:
	{
		returnValue = F("Meyersgasse");
		break;
	}
	case 1907:
	{
		returnValue = F("Michaelshof");
		break;
	}
	case 1908:
	{
		returnValue = F("Mildred-Harnack-Weg");
		break;
	}
	case 1909:
	{
		returnValue = F("Minna-Naumann-Weg");
		break;
	}
	case 1910:
	{
		returnValue = F("Mittelgasse");
		break;
	}
	case 1911:
	{
		returnValue = F("Mittelmark");
		break;
	}
	case 1912:
	{
		returnValue = F("Mittelpunktschule");
		break;
	}
	case 1913:
	{
		returnValue = F("Mittelstraße");
		break;
	}
	case 1914:
	{
		returnValue = F("Mittelweg");
		break;
	}
	case 1915:
	{
		returnValue = F("Mittermaierstraße");
		break;
	}
	case 1916:
	{
		returnValue = F("Mittlerer Heegweg");
		break;
	}
	case 1917:
	{
		returnValue = F("Möhrengasse");
		break;
	}
	case 1918:
	{
		returnValue = F("Mönchsgasse");
		break;
	}
	case 1919:
	{
		returnValue = F("Möserstraße");
		break;
	}
	case 1920:
	{
		returnValue = F("Mohastraße");
		break;
	}
	case 1921:
	{
		returnValue = F("Mohnberg");
		break;
	}
	case 1922:
	{
		returnValue = F("Mohnstrauch");
		break;
	}
	case 1923:
	{
		returnValue = F("Mohnweg");
		break;
	}
	case 1924:
	{
		returnValue = F("Mohrunger Weg");
		break;
	}
	case 1925:
	{
		returnValue = F("Mollbornsweg");
		break;
	}
	case 1926:
	{
		returnValue = F("Mollner Straße");
		break;
	}
	case 1927:
	{
		returnValue = F("Moltkestraße");
		break;
	}
	case 1928:
	{
		returnValue = F("Monroestraße");
		break;
	}
	case 1929:
	{
		returnValue = F("Moorgasse");
		break;
	}
	case 1930:
	{
		returnValue = F("Moosweg");
		break;
	}
	case 1931:
	{
		returnValue = F("Mozartstraße");
		break;
	}
	case 1932:
	{
		returnValue = F("Mragowo Straße");
		break;
	}
	case 1933:
	{
		returnValue = F("Mückenstrauch");
		break;
	}
	case 1934:
	{
		returnValue = F("Mühläckerring");
		break;
	}
	case 1935:
	{
		returnValue = F("Mühlbergstraße");
		break;
	}
	case 1936:
	{
		returnValue = F("Mühlecke");
		break;
	}
	case 1937:
	{
		returnValue = F("Mühlenweg");
		break;
	}
	case 1938:
	{
		returnValue = F("Mühlgarten");
		break;
	}
	case 1939:
	{
		returnValue = F("Mühlgasse");
		break;
	}
	case 1940:
	{
		returnValue = F("Mühlhäuser Straße");
		break;
	}
	case 1941:
	{
		returnValue = F("Mühlrain");
		break;
	}
	case 1942:
	{
		returnValue = F("Mühlstraße");
		break;
	}
	case 1943:
	{
		returnValue = F("Mühlweg");
		break;
	}
	case 1944:
	{
		returnValue = F("Mühlwiese");
		break;
	}
	case 1945:
	{
		returnValue = F("Müllereck");
		break;
	}
	case 1946:
	{
		returnValue = F("Müllerecke");
		break;
	}
	case 1947:
	{
		returnValue = F("Müllerweg");
		break;
	}
	case 1948:
	{
		returnValue = F("Münchgasse");
		break;
	}
	case 1949:
	{
		returnValue = F("Münsterer Straße");
		break;
	}
	case 1950:
	{
		returnValue = F("Münzenberger Straße");
		break;
	}
	case 1951:
	{
		returnValue = F("Münzenberger Weg");
		break;
	}
	case 1952:
	{
		returnValue = F("Muhlbrücken");
		break;
	}
	case 1953:
	{
		returnValue = F("Muschenheimer Straße");
		break;
	}
	case 1954:
	{
		returnValue = F("Muschenheimer Weg");
		break;
	}
	case 1955:
	{
		returnValue = F("Muttersholtzer Straße");
		break;
	}
	case 1956:
	{
		returnValue = F("Nachtigallenweg");
		break;
	}
	case 1957:
	{
		returnValue = F("Nahrungsberg");
		break;
	}
	case 1958:
	{
		returnValue = F("Narzissenweg");
		break;
	}
	case 1959:
	{
		returnValue = F("Nassauer Ring");
		break;
	}
	case 1960:
	{
		returnValue = F("Nassauer Straße");
		break;
	}
	case 1961:
	{
		returnValue = F("Nebengasse");
		break;
	}
	case 1962:
	{
		returnValue = F("Nelkenstraße");
		break;
	}
	case 1963:
	{
		returnValue = F("Nelkenweg");
		break;
	}
	case 1964:
	{
		returnValue = F("Nelly-Sachs-Weg");
		break;
	}
	case 1965:
	{
		returnValue = F("Netanyastraße");
		break;
	}
	case 1966:
	{
		returnValue = F("Neue Fahrt");
		break;
	}
	case 1967:
	{
		returnValue = F("Neue Licher Pforte");
		break;
	}
	case 1968:
	{
		returnValue = F("Neue Mitte");
		break;
	}
	case 1969:
	{
		returnValue = F("Neue Straße");
		break;
	}
	case 1970:
	{
		returnValue = F("Neue Wegscheide");
		break;
	}
	case 1971:
	{
		returnValue = F("Neuen Bäue");
		break;
	}
	case 1972:
	{
		returnValue = F("Neuenweg");
		break;
	}
	case 1973:
	{
		returnValue = F("Neuer Weg");
		break;
	}
	case 1974:
	{
		returnValue = F("Neugasse");
		break;
	}
	case 1975:
	{
		returnValue = F("Neuhöfer Weg");
		break;
	}
	case 1976:
	{
		returnValue = F("Neuhof");
		break;
	}
	case 1977:
	{
		returnValue = F("Neumühle");
		break;
	}
	case 1978:
	{
		returnValue = F("Neupforte");
		break;
	}
	case 1979:
	{
		returnValue = F("Neustadt");
		break;
	}
	case 1980:
	{
		returnValue = F("Neuwiesenweg");
		break;
	}
	case 1981:
	{
		returnValue = F("Niddaer Straße");
		break;
	}
	case 1982:
	{
		returnValue = F("Niebergallweg");
		break;
	}
	case 1983:
	{
		returnValue = F("Niederfeldstraße");
		break;
	}
	case 1984:
	{
		returnValue = F("Niederhofen");
		break;
	}
	case 1985:
	{
		returnValue = F("Niederkleener Straße");
		break;
	}
	case 1986:
	{
		returnValue = F("Nikolaus-Otto-Straße");
		break;
	}
	case 1987:
	{
		returnValue = F("Nollgasse");
		break;
	}
	case 1988:
	{
		returnValue = F("Nonnenröther Straße");
		break;
	}
	case 1989:
	{
		returnValue = F("Nonnenröther Weg");
		break;
	}
	case 1990:
	{
		returnValue = F("Nonnenweg");
		break;
	}
	case 1991:
	{
		returnValue = F("Nordanlage");
		break;
	}
	case 1992:
	{
		returnValue = F("Nordecker Straße");
		break;
	}
	case 1993:
	{
		returnValue = F("Nordhäuser Weg");
		break;
	}
	case 1994:
	{
		returnValue = F("Nordsternweg");
		break;
	}
	case 1995:
	{
		returnValue = F("Nordstraße");
		break;
	}
	case 1996:
	{
		returnValue = F("Nußberg");
		break;
	}
	case 1997:
	{
		returnValue = F("Nußbergweg");
		break;
	}
	case 1998:
	{
		returnValue = F("Nußgasse");
		break;
	}
	case 1999:
	{
		returnValue = F("Nußhecke");
		break;
	}
	case 2000:
	{
		returnValue = F("OVAG-Straße");
		break;
	}
	case 2001:
	{
		returnValue = F("Obbornhofener Straße");
		break;
	}
	case 2002:
	{
		returnValue = F("Ober-Bessinger Straße");
		break;
	}
	case 2003:
	{
		returnValue = F("Ober-Widdersheimer-Weg");
		break;
	}
	case 2004:
	{
		returnValue = F("Ober dem Hohlweg");
		break;
	}
	case 2005:
	{
		returnValue = F("Ober der Lumda");
		break;
	}
	case 2006:
	{
		returnValue = F("Oberauweg");
		break;
	}
	case 2007:
	{
		returnValue = F("Oberdorfstraße");
		break;
	}
	case 2008:
	{
		returnValue = F("Obere Burgstraße");
		break;
	}
	case 2009:
	{
		returnValue = F("Obere Hainbergstraße");
		break;
	}
	case 2010:
	{
		returnValue = F("Obere Langgasse");
		break;
	}
	case 2011:
	{
		returnValue = F("Obere Mühle");
		break;
	}
	case 2012:
	{
		returnValue = F("Obere Pforte");
		break;
	}
	case 2013:
	{
		returnValue = F("Obere Ziegelhütte");
		break;
	}
	case 2014:
	{
		returnValue = F("Oberer Gleiberger Weg");
		break;
	}
	case 2015:
	{
		returnValue = F("Oberer Hardthof");
		break;
	}
	case 2016:
	{
		returnValue = F("Obergarten");
		break;
	}
	case 2017:
	{
		returnValue = F("Obergasse");
		break;
	}
	case 2018:
	{
		returnValue = F("Oberhalb der Waldmühle");
		break;
	}
	case 2019:
	{
		returnValue = F("Oberhof");
		break;
	}
	case 2020:
	{
		returnValue = F("Oberhofstraße");
		break;
	}
	case 2021:
	{
		returnValue = F("Oberkleener Straße");
		break;
	}
	case 2022:
	{
		returnValue = F("Oberlachweg");
		break;
	}
	case 2023:
	{
		returnValue = F("Oberlinweg");
		break;
	}
	case 2024:
	{
		returnValue = F("Obermühle");
		break;
	}
	case 2025:
	{
		returnValue = F("Oberndorfer Straße");
		break;
	}
	case 2026:
	{
		returnValue = F("Oberpforte");
		break;
	}
	case 2027:
	{
		returnValue = F("Oberseener Hof");
		break;
	}
	case 2028:
	{
		returnValue = F("Oberseener Weg");
		break;
	}
	case 2029:
	{
		returnValue = F("Oberstadt");
		break;
	}
	case 2030:
	{
		returnValue = F("Oberstraße");
		break;
	}
	case 2031:
	{
		returnValue = F("Oberstruth");
		break;
	}
	case 2032:
	{
		returnValue = F("Obertorstraße");
		break;
	}
	case 2033:
	{
		returnValue = F("Oberweg");
		break;
	}
	case 2034:
	{
		returnValue = F("Ockerweg");
		break;
	}
	case 2035:
	{
		returnValue = F("Odenhäuser Straße");
		break;
	}
	case 2036:
	{
		returnValue = F("Öbersbach");
		break;
	}
	case 2037:
	{
		returnValue = F("Oesgrundring");
		break;
	}
	case 2038:
	{
		returnValue = F("Ohlebergsweg");
		break;
	}
	case 2039:
	{
		returnValue = F("Ohlengasse");
		break;
	}
	case 2040:
	{
		returnValue = F("Ojenberg");
		break;
	}
	case 2041:
	{
		returnValue = F("Oppenröder Straße");
		break;
	}
	case 2042:
	{
		returnValue = F("Oppenröder Weg");
		break;
	}
	case 2043:
	{
		returnValue = F("Oppersgasse");
		break;
	}
	case 2044:
	{
		returnValue = F("Ortsberingweg");
		break;
	}
	case 2045:
	{
		returnValue = F("Ortsstraße");
		break;
	}
	case 2046:
	{
		returnValue = F("Ostanlage");
		break;
	}
	case 2047:
	{
		returnValue = F("Ostendstraße");
		break;
	}
	case 2048:
	{
		returnValue = F("Osterwiesenweg");
		break;
	}
	case 2049:
	{
		returnValue = F("Ostpreußenstraße");
		break;
	}
	case 2050:
	{
		returnValue = F("Oswaldsgarten");
		break;
	}
	case 2051:
	{
		returnValue = F("Ottilienhof");
		break;
	}
	case 2052:
	{
		returnValue = F("Otto-Behaghel-Straße");
		break;
	}
	case 2053:
	{
		returnValue = F("Otto-Benecke-Weg");
		break;
	}
	case 2054:
	{
		returnValue = F("Otto-Bepler-Straße");
		break;
	}
	case 2055:
	{
		returnValue = F("Otto-Erdmann-Straße");
		break;
	}
	case 2056:
	{
		returnValue = F("Otto-Schulte-Straße");
		break;
	}
	case 2057:
	{
		returnValue = F("Otto-Zöckler-Straße");
		break;
	}
	case 2058:
	{
		returnValue = F("Palisadenweg");
		break;
	}
	case 2059:
	{
		returnValue = F("Panoramaweg");
		break;
	}
	case 2060:
	{
		returnValue = F("Pappelrain");
		break;
	}
	case 2061:
	{
		returnValue = F("Pappelstraße");
		break;
	}
	case 2062:
	{
		returnValue = F("Pappelweg");
		break;
	}
	case 2063:
	{
		returnValue = F("Parkstraße");
		break;
	}
	case 2064:
	{
		returnValue = F("Parkweg");
		break;
	}
	case 2065:
	{
		returnValue = F("Pater-Delp-Straße");
		break;
	}
	case 2066:
	{
		returnValue = F("Paul-Gerhardt-Straße");
		break;
	}
	case 2067:
	{
		returnValue = F("Paul-Hutten-Ring");
		break;
	}
	case 2068:
	{
		returnValue = F("Paul-Meimberg-Straße");
		break;
	}
	case 2069:
	{
		returnValue = F("Paul-Schneider-Straße");
		break;
	}
	case 2070:
	{
		returnValue = F("Paul-Zipp-Straße");
		break;
	}
	case 2071:
	{
		returnValue = F("Paulinenstraße");
		break;
	}
	case 2072:
	{
		returnValue = F("Paulusgarten");
		break;
	}
	case 2073:
	{
		returnValue = F("Pauluswiese");
		break;
	}
	case 2074:
	{
		returnValue = F("Peinmühle");
		break;
	}
	case 2075:
	{
		returnValue = F("Perchstetten");
		break;
	}
	case 2076:
	{
		returnValue = F("Pestalozzistraße");
		break;
	}
	case 2077:
	{
		returnValue = F("Petersweg");
		break;
	}
	case 2078:
	{
		returnValue = F("Petersweiher");
		break;
	}
	case 2079:
	{
		returnValue = F("Pfaffenkreben");
		break;
	}
	case 2080:
	{
		returnValue = F("Pfarrbusch");
		break;
	}
	case 2081:
	{
		returnValue = F("Pfarrecke");
		break;
	}
	case 2082:
	{
		returnValue = F("Pfarrgarten");
		break;
	}
	case 2083:
	{
		returnValue = F("Pfarrgasse");
		break;
	}
	case 2084:
	{
		returnValue = F("Pfarrhof");
		break;
	}
	case 2085:
	{
		returnValue = F("Pfarrstraße");
		break;
	}
	case 2086:
	{
		returnValue = F("Pfarrweg");
		break;
	}
	case 2087:
	{
		returnValue = F("Pfarrwiesen");
		break;
	}
	case 2088:
	{
		returnValue = F("Pfingstkopfweg");
		break;
	}
	case 2089:
	{
		returnValue = F("Pfingstweg");
		break;
	}
	case 2090:
	{
		returnValue = F("Pfingstweide");
		break;
	}
	case 2091:
	{
		returnValue = F("Pfortgärten");
		break;
	}
	case 2092:
	{
		returnValue = F("Philipp-Reis-Straße");
		break;
	}
	case 2093:
	{
		returnValue = F("Philipp-Scheidemann-Straße");
		break;
	}
	case 2094:
	{
		returnValue = F("Philosophenstraße");
		break;
	}
	case 2095:
	{
		returnValue = F("Philosophenwald");
		break;
	}
	case 2096:
	{
		returnValue = F("Pinggasse");
		break;
	}
	case 2097:
	{
		returnValue = F("Pistorstraße");
		break;
	}
	case 2098:
	{
		returnValue = F("Platanenring");
		break;
	}
	case 2099:
	{
		returnValue = F("Plattweg");
		break;
	}
	case 2100:
	{
		returnValue = F("Platz Clouange");
		break;
	}
	case 2101:
	{
		returnValue = F("Platz der Deutschen Einheit");
		break;
	}
	case 2102:
	{
		returnValue = F("Plockstraße");
		break;
	}
	case 2103:
	{
		returnValue = F("Pohlheimer Straße");
		break;
	}
	case 2104:
	{
		returnValue = F("Pommernstraße");
		break;
	}
	case 2105:
	{
		returnValue = F("Porstendorfer Straße");
		break;
	}
	case 2106:
	{
		returnValue = F("Portegasse");
		break;
	}
	case 2107:
	{
		returnValue = F("Posener Straße");
		break;
	}
	case 2108:
	{
		returnValue = F("Poststraße");
		break;
	}
	case 2109:
	{
		returnValue = F("Potsdamer Straße");
		break;
	}
	case 2110:
	{
		returnValue = F("Prachtstraße");
		break;
	}
	case 2111:
	{
		returnValue = F("Primelweg");
		break;
	}
	case 2112:
	{
		returnValue = F("Professorenweg");
		break;
	}
	case 2113:
	{
		returnValue = F("Prophetenmühlenweg");
		break;
	}
	case 2114:
	{
		returnValue = F("Quellenstraße");
		break;
	}
	case 2115:
	{
		returnValue = F("Rabegasse");
		break;
	}
	case 2116:
	{
		returnValue = F("Rabenauer Straße");
		break;
	}
	case 2117:
	{
		returnValue = F("Rabenaustraße");
		break;
	}
	case 2118:
	{
		returnValue = F("Rabenweg");
		break;
	}
	case 2119:
	{
		returnValue = F("Rahmengasse");
		break;
	}
	case 2120:
	{
		returnValue = F("Raiffeisenstraße");
		break;
	}
	case 2121:
	{
		returnValue = F("Rainer-Maria-Rilke-Straße");
		break;
	}
	case 2122:
	{
		returnValue = F("Rainstraße");
		break;
	}
	case 2123:
	{
		returnValue = F("Rainweg");
		break;
	}
	case 2124:
	{
		returnValue = F("Rambachweg");
		break;
	}
	case 2125:
	{
		returnValue = F("Rathausgasse");
		break;
	}
	case 2126:
	{
		returnValue = F("Rathausplatz");
		break;
	}
	case 2127:
	{
		returnValue = F("Rathausstraße");
		break;
	}
	case 2128:
	{
		returnValue = F("Rathenaustraße");
		break;
	}
	case 2129:
	{
		returnValue = F("Ratsweg");
		break;
	}
	case 2130:
	{
		returnValue = F("Raum");
		break;
	}
	case 2131:
	{
		returnValue = F("Rebhuhnpfad");
		break;
	}
	case 2132:
	{
		returnValue = F("Rechtenbacher Hohl");
		break;
	}
	case 2133:
	{
		returnValue = F("Reehof");
		break;
	}
	case 2134:
	{
		returnValue = F("Rehschneise");
		break;
	}
	case 2135:
	{
		returnValue = F("Rehweg");
		break;
	}
	case 2136:
	{
		returnValue = F("Rehweide");
		break;
	}
	case 2137:
	{
		returnValue = F("Reiberg");
		break;
	}
	case 2138:
	{
		returnValue = F("Reichelsberg");
		break;
	}
	case 2139:
	{
		returnValue = F("Reichenberger Straße");
		break;
	}
	case 2140:
	{
		returnValue = F("Reichensand");
		break;
	}
	case 2141:
	{
		returnValue = F("Reichgasse");
		break;
	}
	case 2142:
	{
		returnValue = F("Reinhard-Mölcher-Weg");
		break;
	}
	case 2143:
	{
		returnValue = F("Reinhard-Strecker-Weg");
		break;
	}
	case 2144:
	{
		returnValue = F("Reinhardshainer Straße");
		break;
	}
	case 2145:
	{
		returnValue = F("Reinhardshainer Weg");
		break;
	}
	case 2146:
	{
		returnValue = F("Reisiger Weg");
		break;
	}
	case 2147:
	{
		returnValue = F("Reiskirchener Straße");
		break;
	}
	case 2148:
	{
		returnValue = F("Renthof");
		break;
	}
	case 2149:
	{
		returnValue = F("Reutergasse");
		break;
	}
	case 2150:
	{
		returnValue = F("Rewestraße");
		break;
	}
	case 2151:
	{
		returnValue = F("Rheinfelser Straße");
		break;
	}
	case 2152:
	{
		returnValue = F("Rheingasse");
		break;
	}
	case 2153:
	{
		returnValue = F("Ricarda-Huch-Straße");
		break;
	}
	case 2154:
	{
		returnValue = F("Richard-Schirrmann-Weg");
		break;
	}
	case 2155:
	{
		returnValue = F("Richard-Wagner-Straße");
		break;
	}
	case 2156:
	{
		returnValue = F("Riedenweg");
		break;
	}
	case 2157:
	{
		returnValue = F("Riedgasse");
		break;
	}
	case 2158:
	{
		returnValue = F("Riedhohl");
		break;
	}
	case 2159:
	{
		returnValue = F("Riedstraße");
		break;
	}
	case 2160:
	{
		returnValue = F("Riedstruth");
		break;
	}
	case 2161:
	{
		returnValue = F("Riedweg");
		break;
	}
	case 2162:
	{
		returnValue = F("Riegelpfad");
		break;
	}
	case 2163:
	{
		returnValue = F("Riegelweg");
		break;
	}
	case 2164:
	{
		returnValue = F("Riehlweg");
		break;
	}
	case 2165:
	{
		returnValue = F("Riesengrabenweg");
		break;
	}
	case 2166:
	{
		returnValue = F("Rillscheid-Ring");
		break;
	}
	case 2167:
	{
		returnValue = F("Rimbergstraße");
		break;
	}
	case 2168:
	{
		returnValue = F("Ringallee");
		break;
	}
	case 2169:
	{
		returnValue = F("Ringstraße");
		break;
	}
	case 2170:
	{
		returnValue = F("Ringweg");
		break;
	}
	case 2171:
	{
		returnValue = F("Rinnstraße");
		break;
	}
	case 2172:
	{
		returnValue = F("Rittergasse");
		break;
	}
	case 2173:
	{
		returnValue = F("Riversplatz");
		break;
	}
	case 2174:
	{
		returnValue = F("Robert-Bosch-Ring");
		break;
	}
	case 2175:
	{
		returnValue = F("Robert-Bosch-Straße");
		break;
	}
	case 2176:
	{
		returnValue = F("Robert-Koch-Straße");
		break;
	}
	case 2177:
	{
		returnValue = F("Robert-Schuman-Straße");
		break;
	}
	case 2178:
	{
		returnValue = F("Robert-Sommer-Straße");
		break;
	}
	case 2179:
	{
		returnValue = F("Rodelberg");
		break;
	}
	case 2180:
	{
		returnValue = F("Rodheimer Straße");
		break;
	}
	case 2181:
	{
		returnValue = F("Rodtbergstraße");
		break;
	}
	case 2182:
	{
		returnValue = F("Rodtgärten");
		break;
	}
	case 2183:
	{
		returnValue = F("Rodthohl");
		break;
	}
	case 2184:
	{
		returnValue = F("Rodweg");
		break;
	}
	case 2185:
	{
		returnValue = F("Röderbergstraße");
		break;
	}
	case 2186:
	{
		returnValue = F("Rödernweg");
		break;
	}
	case 2187:
	{
		returnValue = F("Röderring");
		break;
	}
	case 2188:
	{
		returnValue = F("Röderstraße");
		break;
	}
	case 2189:
	{
		returnValue = F("Röderweg");
		break;
	}
	case 2190:
	{
		returnValue = F("Rödgener Straße");
		break;
	}
	case 2191:
	{
		returnValue = F("Römerstraße");
		break;
	}
	case 2192:
	{
		returnValue = F("Römheldstraße");
		break;
	}
	case 2193:
	{
		returnValue = F("Röntgenstraße");
		break;
	}
	case 2194:
	{
		returnValue = F("Rolshausener Straße");
		break;
	}
	case 2195:
	{
		returnValue = F("Roonstraße");
		break;
	}
	case 2196:
	{
		returnValue = F("Rooseveltstraße");
		break;
	}
	case 2197:
	{
		returnValue = F("Rosengasse");
		break;
	}
	case 2198:
	{
		returnValue = F("Rosenpfad");
		break;
	}
	case 2199:
	{
		returnValue = F("Rosenstraße");
		break;
	}
	case 2200:
	{
		returnValue = F("Rosenweg");
		break;
	}
	case 2201:
	{
		returnValue = F("Rotfeldstraße");
		break;
	}
	case 2202:
	{
		returnValue = F("Rothof");
		break;
	}
	case 2203:
	{
		returnValue = F("Rothweg");
		break;
	}
	case 2204:
	{
		returnValue = F("Rottweg");
		break;
	}
	case 2205:
	{
		returnValue = F("Rudolf-Buchheim-Straße");
		break;
	}
	case 2206:
	{
		returnValue = F("Rudolf-Diesel-Straße");
		break;
	}
	case 2207:
	{
		returnValue = F("Rudolf-Harbig-Straße");
		break;
	}
	case 2208:
	{
		returnValue = F("Rübenauer Straße");
		break;
	}
	case 2209:
	{
		returnValue = F("Rüddingshäuser Straße");
		break;
	}
	case 2210:
	{
		returnValue = F("Rühlshof");
		break;
	}
	case 2211:
	{
		returnValue = F("Ruhbanksweg");
		break;
	}
	case 2212:
	{
		returnValue = F("Ruhberg");
		break;
	}
	case 2213:
	{
		returnValue = F("Rupertisstraße");
		break;
	}
	case 2214:
	{
		returnValue = F("Ruppertsburger Straße");
		break;
	}
	case 2215:
	{
		returnValue = F("Ruppertsgasse");
		break;
	}
	case 2216:
	{
		returnValue = F("Ruttershäuser Straße");
		break;
	}
	case 2217:
	{
		returnValue = F("Ruttershäuser Weg");
		break;
	}
	case 2218:
	{
		returnValue = F("Ruttershausener Straße");
		break;
	}
	case 2219:
	{
		returnValue = F("Saalgasse");
		break;
	}
	case 2220:
	{
		returnValue = F("Saarlandstraße");
		break;
	}
	case 2221:
	{
		returnValue = F("Saasener Straße");
		break;
	}
	case 2222:
	{
		returnValue = F("Saasener Weg");
		break;
	}
	case 2223:
	{
		returnValue = F("Sackgasse");
		break;
	}
	case 2224:
	{
		returnValue = F("Sälzerstraße");
		break;
	}
	case 2225:
	{
		returnValue = F("Salomestraße");
		break;
	}
	case 2226:
	{
		returnValue = F("Salzböder Weg");
		break;
	}
	case 2227:
	{
		returnValue = F("Sandacker");
		break;
	}
	case 2228:
	{
		returnValue = F("Sanderweg");
		break;
	}
	case 2229:
	{
		returnValue = F("Sandfeld");
		break;
	}
	case 2230:
	{
		returnValue = F("Sandgasse");
		break;
	}
	case 2231:
	{
		returnValue = F("Sandkaute");
		break;
	}
	case 2232:
	{
		returnValue = F("Sandkauter Weg");
		break;
	}
	case 2233:
	{
		returnValue = F("Sandusweg");
		break;
	}
	case 2234:
	{
		returnValue = F("Sandweg");
		break;
	}
	case 2235:
	{
		returnValue = F("Sauerbrunnengasse");
		break;
	}
	case 2236:
	{
		returnValue = F("Schaafhausweg");
		break;
	}
	case 2237:
	{
		returnValue = F("Schaal");
		break;
	}
	case 2238:
	{
		returnValue = F("Schadenbacher Straße");
		break;
	}
	case 2239:
	{
		returnValue = F("Schäferbrunnen");
		break;
	}
	case 2240:
	{
		returnValue = F("Schäfergasse");
		break;
	}
	case 2241:
	{
		returnValue = F("Schäferstraße");
		break;
	}
	case 2242:
	{
		returnValue = F("Schälgärten");
		break;
	}
	case 2243:
	{
		returnValue = F("Schafsweg");
		break;
	}
	case 2244:
	{
		returnValue = F("Schanzenstraße");
		break;
	}
	case 2245:
	{
		returnValue = F("Schelkenwiese");
		break;
	}
	case 2246:
	{
		returnValue = F("Scheuergasse");
		break;
	}
	case 2247:
	{
		returnValue = F("Schieferstraße");
		break;
	}
	case 2248:
	{
		returnValue = F("Schiessgärten");
		break;
	}
	case 2249:
	{
		returnValue = F("Schießrain");
		break;
	}
	case 2250:
	{
		returnValue = F("Schiessrain");
		break;
	}
	case 2251:
	{
		returnValue = F("Schiffenberger Weg");
		break;
	}
	case 2252:
	{
		returnValue = F("Schiffenbergstraße");
		break;
	}
	case 2253:
	{
		returnValue = F("Schiffenweg");
		break;
	}
	case 2254:
	{
		returnValue = F("Schildberg");
		break;
	}
	case 2255:
	{
		returnValue = F("Schillerstraße");
		break;
	}
	case 2256:
	{
		returnValue = F("Schlachthofstraße");
		break;
	}
	case 2257:
	{
		returnValue = F("Schlagmühle");
		break;
	}
	case 2258:
	{
		returnValue = F("Schlangenzahl");
		break;
	}
	case 2259:
	{
		returnValue = F("Schleenbergweg");
		break;
	}
	case 2260:
	{
		returnValue = F("Schlehdorn");
		break;
	}
	case 2261:
	{
		returnValue = F("Schlehenweg");
		break;
	}
	case 2262:
	{
		returnValue = F("Schlesierstraße");
		break;
	}
	case 2263:
	{
		returnValue = F("Schlesische Straße");
		break;
	}
	case 2264:
	{
		returnValue = F("Schloß");
		break;
	}
	case 2265:
	{
		returnValue = F("Schloss Friedelhausen");
		break;
	}
	case 2266:
	{
		returnValue = F("Schlossgasse");
		break;
	}
	case 2267:
	{
		returnValue = F("Schloßgasse");
		break;
	}
	case 2268:
	{
		returnValue = F("Schloßstraße");
		break;
	}
	case 2269:
	{
		returnValue = F("Schmalhartstraße");
		break;
	}
	case 2270:
	{
		returnValue = F("Schmalkaldener Weg");
		break;
	}
	case 2271:
	{
		returnValue = F("Schmelz");
		break;
	}
	case 2272:
	{
		returnValue = F("Schmelzweg");
		break;
	}
	case 2273:
	{
		returnValue = F("Schmiedecke");
		break;
	}
	case 2274:
	{
		returnValue = F("Schmiedgasse");
		break;
	}
	case 2275:
	{
		returnValue = F("Schmittgraben");
		break;
	}
	case 2276:
	{
		returnValue = F("Schmuckental");
		break;
	}
	case 2277:
	{
		returnValue = F("Schneiderberg");
		break;
	}
	case 2278:
	{
		returnValue = F("Schneidergasse");
		break;
	}
	case 2279:
	{
		returnValue = F("Schneiderhenn");
		break;
	}
	case 2280:
	{
		returnValue = F("Schnepfenhain");
		break;
	}
	case 2281:
	{
		returnValue = F("Schneppenhain");
		break;
	}
	case 2282:
	{
		returnValue = F("Schnorrnberg");
		break;
	}
	case 2283:
	{
		returnValue = F("Schöne Aussicht");
		break;
	}
	case 2284:
	{
		returnValue = F("Schottener Straße");
		break;
	}
	case 2285:
	{
		returnValue = F("Schotterweg");
		break;
	}
	case 2286:
	{
		returnValue = F("Schottstraße");
		break;
	}
	case 2287:
	{
		returnValue = F("Schreinersmühle");
		break;
	}
	case 2288:
	{
		returnValue = F("Schubertstraße");
		break;
	}
	case 2289:
	{
		returnValue = F("Schützenstraße");
		break;
	}
	case 2290:
	{
		returnValue = F("Schützenweg");
		break;
	}
	case 2291:
	{
		returnValue = F("Schulecke");
		break;
	}
	case 2292:
	{
		returnValue = F("Schulgasse");
		break;
	}
	case 2293:
	{
		returnValue = F("Schulschwan");
		break;
	}
	case 2294:
	{
		returnValue = F("Schulstraße");
		break;
	}
	case 2295:
	{
		returnValue = F("Schumannstraße");
		break;
	}
	case 2296:
	{
		returnValue = F("Schuppstraße");
		break;
	}
	case 2297:
	{
		returnValue = F("Schur");
		break;
	}
	case 2298:
	{
		returnValue = F("Schustergasse");
		break;
	}
	case 2299:
	{
		returnValue = F("Schutzbacher Weg");
		break;
	}
	case 2300:
	{
		returnValue = F("Schwalbachacker");
		break;
	}
	case 2301:
	{
		returnValue = F("Schwalbenpfad");
		break;
	}
	case 2302:
	{
		returnValue = F("Schwalbenweg");
		break;
	}
	case 2303:
	{
		returnValue = F("Schwan");
		break;
	}
	case 2304:
	{
		returnValue = F("Schwarzacker");
		break;
	}
	case 2305:
	{
		returnValue = F("Schwarze Ellergasse");
		break;
	}
	case 2306:
	{
		returnValue = F("Schwarze Hohl");
		break;
	}
	case 2307:
	{
		returnValue = F("Schwarzer Brand");
		break;
	}
	case 2308:
	{
		returnValue = F("Schwarzlachweg");
		break;
	}
	case 2309:
	{
		returnValue = F("Schwarztorweg");
		break;
	}
	case 2310:
	{
		returnValue = F("Schwimmbadstraße");
		break;
	}
	case 2311:
	{
		returnValue = F("Schwimmbadweg");
		break;
	}
	case 2312:
	{
		returnValue = F("Secklerhohl");
		break;
	}
	case 2313:
	{
		returnValue = F("Sedderichweg");
		break;
	}
	case 2314:
	{
		returnValue = F("Seegebiet");
		break;
	}
	case 2315:
	{
		returnValue = F("Seeküppelstraße");
		break;
	}
	case 2316:
	{
		returnValue = F("Seelenhofgasse");
		break;
	}
	case 2317:
	{
		returnValue = F("Seemühle");
		break;
	}
	case 2318:
	{
		returnValue = F("Seentalstraße");
		break;
	}
	case 2319:
	{
		returnValue = F("Seestraße");
		break;
	}
	case 2320:
	{
		returnValue = F("Seewiese");
		break;
	}
	case 2321:
	{
		returnValue = F("Seewiesenstraße");
		break;
	}
	case 2322:
	{
		returnValue = F("Sellnberg");
		break;
	}
	case 2323:
	{
		returnValue = F("Sellnröder Straße");
		break;
	}
	case 2324:
	{
		returnValue = F("Seltersweg");
		break;
	}
	case 2325:
	{
		returnValue = F("Senckenbergstraße");
		break;
	}
	case 2326:
	{
		returnValue = F("Siebenhäusergasse");
		break;
	}
	case 2327:
	{
		returnValue = F("Sieboldstraße");
		break;
	}
	case 2328:
	{
		returnValue = F("Siedlerstraße");
		break;
	}
	case 2329:
	{
		returnValue = F("Siedlung");
		break;
	}
	case 2330:
	{
		returnValue = F("Siedlungsstraße");
		break;
	}
	case 2331:
	{
		returnValue = F("Siegmund-Heichelheim-Straße");
		break;
	}
	case 2332:
	{
		returnValue = F("Siemensstraße");
		break;
	}
	case 2333:
	{
		returnValue = F("Silberweg");
		break;
	}
	case 2334:
	{
		returnValue = F("Silcher Straße");
		break;
	}
	case 2335:
	{
		returnValue = F("Silcherstraße");
		break;
	}
	case 2336:
	{
		returnValue = F("Simchesweg");
		break;
	}
	case 2337:
	{
		returnValue = F("Skyline-Blick");
		break;
	}
	case 2338:
	{
		returnValue = F("Solmser Straße");
		break;
	}
	case 2339:
	{
		returnValue = F("Solweg");
		break;
	}
	case 2340:
	{
		returnValue = F("Sommerberg");
		break;
	}
	case 2341:
	{
		returnValue = F("Sommersmühle");
		break;
	}
	case 2342:
	{
		returnValue = F("Sonnenhof");
		break;
	}
	case 2343:
	{
		returnValue = F("Sonnenstraße");
		break;
	}
	case 2344:
	{
		returnValue = F("Sonnenweg");
		break;
	}
	case 2345:
	{
		returnValue = F("Sorausweg");
		break;
	}
	case 2346:
	{
		returnValue = F("Sorguesplatz");
		break;
	}
	case 2347:
	{
		returnValue = F("Spechtweg");
		break;
	}
	case 2348:
	{
		returnValue = F("Spenerweg");
		break;
	}
	case 2349:
	{
		returnValue = F("Sperberwegpfad");
		break;
	}
	case 2350:
	{
		returnValue = F("Spitzengärten");
		break;
	}
	case 2351:
	{
		returnValue = F("Spitzwegring");
		break;
	}
	case 2352:
	{
		returnValue = F("Spörhasestraße");
		break;
	}
	case 2353:
	{
		returnValue = F("Sportfeld");
		break;
	}
	case 2354:
	{
		returnValue = F("Sportplatzstraße");
		break;
	}
	case 2355:
	{
		returnValue = F("Sportplatzweg");
		break;
	}
	case 2356:
	{
		returnValue = F("St.-Ulrich-Ring");
		break;
	}
	case 2357:
	{
		returnValue = F("Stadtwald");
		break;
	}
	case 2358:
	{
		returnValue = F("Stangenröder Straße");
		break;
	}
	case 2359:
	{
		returnValue = F("Stangenröder Weg");
		break;
	}
	case 2360:
	{
		returnValue = F("Starenweg");
		break;
	}
	case 2361:
	{
		returnValue = F("Starkenburger Straße");
		break;
	}
	case 2362:
	{
		returnValue = F("Staufenberger Straße");
		break;
	}
	case 2363:
	{
		returnValue = F("Staufenberger Weg");
		break;
	}
	case 2364:
	{
		returnValue = F("Staufenbergring");
		break;
	}
	case 2365:
	{
		returnValue = F("Stefan-Bellof-Straße");
		break;
	}
	case 2366:
	{
		returnValue = F("Stefan-Kuhn-Straße");
		break;
	}
	case 2367:
	{
		returnValue = F("Stefan Bellof-Straße");
		break;
	}
	case 2368:
	{
		returnValue = F("Steggartenweg");
		break;
	}
	case 2369:
	{
		returnValue = F("Steggasse");
		break;
	}
	case 2370:
	{
		returnValue = F("Steinacker");
		break;
	}
	case 2371:
	{
		returnValue = F("Steinäcker");
		break;
	}
	case 2372:
	{
		returnValue = F("Steinbacher Gärten");
		break;
	}
	case 2373:
	{
		returnValue = F("Steinbacher Straße");
		break;
	}
	case 2374:
	{
		returnValue = F("Steinberger Straße");
		break;
	}
	case 2375:
	{
		returnValue = F("Steinberger Weg");
		break;
	}
	case 2376:
	{
		returnValue = F("Steinbergstraße");
		break;
	}
	case 2377:
	{
		returnValue = F("Steinborner Gärten");
		break;
	}
	case 2378:
	{
		returnValue = F("Steinbruch");
		break;
	}
	case 2379:
	{
		returnValue = F("Steinbruchstraße");
		break;
	}
	case 2380:
	{
		returnValue = F("Steinbruchsweg");
		break;
	}
	case 2381:
	{
		returnValue = F("Steinbusch");
		break;
	}
	case 2382:
	{
		returnValue = F("Steineckerweg");
		break;
	}
	case 2383:
	{
		returnValue = F("Steiner Berg");
		break;
	}
	case 2384:
	{
		returnValue = F("Steinerne Brücke");
		break;
	}
	case 2385:
	{
		returnValue = F("Steinerweg");
		break;
	}
	case 2386:
	{
		returnValue = F("Steinesmühle");
		break;
	}
	case 2387:
	{
		returnValue = F("Steinesstraße");
		break;
	}
	case 2388:
	{
		returnValue = F("Steinesweg");
		break;
	}
	case 2389:
	{
		returnValue = F("Steinfurthstraße");
		break;
	}
	case 2390:
	{
		returnValue = F("Steingasse");
		break;
	}
	case 2391:
	{
		returnValue = F("Steinheimer Straße");
		break;
	}
	case 2392:
	{
		returnValue = F("Steinhohl");
		break;
	}
	case 2393:
	{
		returnValue = F("Steinkaute");
		break;
	}
	case 2394:
	{
		returnValue = F("Steinkauter Weg");
		break;
	}
	case 2395:
	{
		returnValue = F("Steinkreuz");
		break;
	}
	case 2396:
	{
		returnValue = F("Steinstraße");
		break;
	}
	case 2397:
	{
		returnValue = F("Steinweg");
		break;
	}
	case 2398:
	{
		returnValue = F("Stephanstraße");
		break;
	}
	case 2399:
	{
		returnValue = F("Sternmark");
		break;
	}
	case 2400:
	{
		returnValue = F("Stettiner Straße");
		break;
	}
	case 2401:
	{
		returnValue = F("Stiegel");
		break;
	}
	case 2402:
	{
		returnValue = F("Stiftstraße");
		break;
	}
	case 2403:
	{
		returnValue = F("Stirnberg");
		break;
	}
	case 2404:
	{
		returnValue = F("Stockhäuser Hof");
		break;
	}
	case 2405:
	{
		returnValue = F("Stockhäuser Weg");
		break;
	}
	case 2406:
	{
		returnValue = F("Stollberg");
		break;
	}
	case 2407:
	{
		returnValue = F("Stolzenmorgen");
		break;
	}
	case 2408:
	{
		returnValue = F("Storchnest");
		break;
	}
	case 2409:
	{
		returnValue = F("Stralsunder Straße");
		break;
	}
	case 2410:
	{
		returnValue = F("Strauchbachweg");
		break;
	}
	case 2411:
	{
		returnValue = F("Strauchhof");
		break;
	}
	case 2412:
	{
		returnValue = F("Strauchweg");
		break;
	}
	case 2413:
	{
		returnValue = F("Strohmühle");
		break;
	}
	case 2414:
	{
		returnValue = F("Struppiusstraße");
		break;
	}
	case 2415:
	{
		returnValue = F("Struppmühle");
		break;
	}
	case 2416:
	{
		returnValue = F("Struppmühlenweg");
		break;
	}
	case 2417:
	{
		returnValue = F("Struthstraße");
		break;
	}
	case 2418:
	{
		returnValue = F("Struthwaldstraße");
		break;
	}
	case 2419:
	{
		returnValue = F("Stuckgasse");
		break;
	}
	case 2420:
	{
		returnValue = F("Studentensteg");
		break;
	}
	case 2421:
	{
		returnValue = F("Studentenweg");
		break;
	}
	case 2422:
	{
		returnValue = F("Stückfeld");
		break;
	}
	case 2423:
	{
		returnValue = F("Sudetenlandstraße");
		break;
	}
	case 2424:
	{
		returnValue = F("Sudetenstraße");
		break;
	}
	case 2425:
	{
		returnValue = F("Südanlage");
		break;
	}
	case 2426:
	{
		returnValue = F("Südhang");
		break;
	}
	case 2427:
	{
		returnValue = F("Südring");
		break;
	}
	case 2428:
	{
		returnValue = F("Südstraße");
		break;
	}
	case 2429:
	{
		returnValue = F("Talstraße");
		break;
	}
	case 2430:
	{
		returnValue = F("Talweg");
		break;
	}
	case 2431:
	{
		returnValue = F("Tannenhof");
		break;
	}
	case 2432:
	{
		returnValue = F("Tannenhofstraße");
		break;
	}
	case 2433:
	{
		returnValue = F("Tannenring");
		break;
	}
	case 2434:
	{
		returnValue = F("Tannenweg");
		break;
	}
	case 2435:
	{
		returnValue = F("Tarjanplatz");
		break;
	}
	case 2436:
	{
		returnValue = F("Taubenäcker");
		break;
	}
	case 2437:
	{
		returnValue = F("Taubenweg");
		break;
	}
	case 2438:
	{
		returnValue = F("Taunusblick");
		break;
	}
	case 2439:
	{
		returnValue = F("Taunusstraße");
		break;
	}
	case 2440:
	{
		returnValue = F("Teichweg");
		break;
	}
	case 2441:
	{
		returnValue = F("Teilgärtenweg");
		break;
	}
	case 2442:
	{
		returnValue = F("Tennenwald");
		break;
	}
	case 2443:
	{
		returnValue = F("Teufelslustgärtchen");
		break;
	}
	case 2444:
	{
		returnValue = F("Teufelswiesenweg");
		break;
	}
	case 2445:
	{
		returnValue = F("Thärstraße");
		break;
	}
	case 2446:
	{
		returnValue = F("Theo-Koch-Straße");
		break;
	}
	case 2447:
	{
		returnValue = F("Theodor-Heuss-Straße");
		break;
	}
	case 2448:
	{
		returnValue = F("Theodor-Storm-Weg");
		break;
	}
	case 2449:
	{
		returnValue = F("Theodor-Völker-Straße");
		break;
	}
	case 2450:
	{
		returnValue = F("Therese-Kalbfleisch-Straße");
		break;
	}
	case 2451:
	{
		returnValue = F("Thielmannweg");
		break;
	}
	case 2452:
	{
		returnValue = F("Thinghof");
		break;
	}
	case 2453:
	{
		returnValue = F("Thomastraße");
		break;
	}
	case 2454:
	{
		returnValue = F("Tiefenhof");
		break;
	}
	case 2455:
	{
		returnValue = F("Tiefenweg");
		break;
	}
	case 2456:
	{
		returnValue = F("Tiergartenstraße");
		break;
	}
	case 2457:
	{
		returnValue = F("Tilsiter Straße");
		break;
	}
	case 2458:
	{
		returnValue = F("Torstraße");
		break;
	}
	case 2459:
	{
		returnValue = F("Totenhäuser Weg");
		break;
	}
	case 2460:
	{
		returnValue = F("Trais-Horloffer Straße");
		break;
	}
	case 2461:
	{
		returnValue = F("Treiser Pfad");
		break;
	}
	case 2462:
	{
		returnValue = F("Treiser Straße");
		break;
	}
	case 2463:
	{
		returnValue = F("Treiser Weg");
		break;
	}
	case 2464:
	{
		returnValue = F("Trieb");
		break;
	}
	case 2465:
	{
		returnValue = F("Triebstraße");
		break;
	}
	case 2466:
	{
		returnValue = F("Trillergässchen");
		break;
	}
	case 2467:
	{
		returnValue = F("Troher Straße");
		break;
	}
	case 2468:
	{
		returnValue = F("Troppauer Straße");
		break;
	}
	case 2469:
	{
		returnValue = F("Tulpenhof");
		break;
	}
	case 2470:
	{
		returnValue = F("Tulpenstraße");
		break;
	}
	case 2471:
	{
		returnValue = F("Tulpenweg");
		break;
	}
	case 2472:
	{
		returnValue = F("Tunnelstraße");
		break;
	}
	case 2473:
	{
		returnValue = F("Turmgärten");
		break;
	}
	case 2474:
	{
		returnValue = F("Turmgäßchen");
		break;
	}
	case 2475:
	{
		returnValue = F("Turmstraße");
		break;
	}
	case 2476:
	{
		returnValue = F("Turmweg");
		break;
	}
	case 2477:
	{
		returnValue = F("Turngasse");
		break;
	}
	case 2478:
	{
		returnValue = F("Turnhallenstraße");
		break;
	}
	case 2479:
	{
		returnValue = F("Turnstraße");
		break;
	}
	case 2480:
	{
		returnValue = F("Ubbelohdeweg");
		break;
	}
	case 2481:
	{
		returnValue = F("Udenborn");
		break;
	}
	case 2482:
	{
		returnValue = F("Udersbergstraße");
		break;
	}
	case 2483:
	{
		returnValue = F("Über der Seife");
		break;
	}
	case 2484:
	{
		returnValue = F("Uferstraße");
		break;
	}
	case 2485:
	{
		returnValue = F("Uferweg");
		break;
	}
	case 2486:
	{
		returnValue = F("Uhlandstraße");
		break;
	}
	case 2487:
	{
		returnValue = F("Ulfaer Straße");
		break;
	}
	case 2488:
	{
		returnValue = F("Ulmenring");
		break;
	}
	case 2489:
	{
		returnValue = F("Ulner Dreieck");
		break;
	}
	case 2490:
	{
		returnValue = F("Unter den Linden");
		break;
	}
	case 2491:
	{
		returnValue = F("Unter der Böhl");
		break;
	}
	case 2492:
	{
		returnValue = F("Unter der Burg");
		break;
	}
	case 2493:
	{
		returnValue = F("Unterbeunde");
		break;
	}
	case 2494:
	{
		returnValue = F("Unterdorf");
		break;
	}
	case 2495:
	{
		returnValue = F("Untere Hainbergstraße");
		break;
	}
	case 2496:
	{
		returnValue = F("Untere Langgasse");
		break;
	}
	case 2497:
	{
		returnValue = F("Untere Pforte");
		break;
	}
	case 2498:
	{
		returnValue = F("Unterecke");
		break;
	}
	case 2499:
	{
		returnValue = F("Unterer Hardthof");
		break;
	}
	case 2500:
	{
		returnValue = F("Untergasse");
		break;
	}
	case 2501:
	{
		returnValue = F("Unterhof");
		break;
	}
	case 2502:
	{
		returnValue = F("Unterm Hardtwäldchen");
		break;
	}
	case 2503:
	{
		returnValue = F("Unterm Steinberg");
		break;
	}
	case 2504:
	{
		returnValue = F("Unterpforte");
		break;
	}
	case 2505:
	{
		returnValue = F("Unterstadt");
		break;
	}
	case 2506:
	{
		returnValue = F("Unterstruth");
		break;
	}
	case 2507:
	{
		returnValue = F("Untertorstraße");
		break;
	}
	case 2508:
	{
		returnValue = F("Ursulum");
		break;
	}
	case 2509:
	{
		returnValue = F("Utpher Kirchenpfad");
		break;
	}
	case 2510:
	{
		returnValue = F("Veilchenweg");
		break;
	}
	case 2511:
	{
		returnValue = F("Veitsberg");
		break;
	}
	case 2512:
	{
		returnValue = F("Versailler Straße");
		break;
	}
	case 2513:
	{
		returnValue = F("Vesperstraße");
		break;
	}
	case 2514:
	{
		returnValue = F("Vetzberger Straße");
		break;
	}
	case 2515:
	{
		returnValue = F("Vetzberger Weg");
		break;
	}
	case 2516:
	{
		returnValue = F("Vetzbergring");
		break;
	}
	case 2517:
	{
		returnValue = F("Villinger Straße");
		break;
	}
	case 2518:
	{
		returnValue = F("Vincergasse");
		break;
	}
	case 2519:
	{
		returnValue = F("Vixröder Straße");
		break;
	}
	case 2520:
	{
		returnValue = F("Vogelhecke");
		break;
	}
	case 2521:
	{
		returnValue = F("Vogelsang");
		break;
	}
	case 2522:
	{
		returnValue = F("Vogelsbergstraße");
		break;
	}
	case 2523:
	{
		returnValue = F("Volpertstriesch");
		break;
	}
	case 2524:
	{
		returnValue = F("Von-Bibra-Straße");
		break;
	}
	case 2525:
	{
		returnValue = F("Von-Galen-Weg");
		break;
	}
	case 2526:
	{
		returnValue = F("Vor dem Attenberg");
		break;
	}
	case 2527:
	{
		returnValue = F("Vor dem Hegwald");
		break;
	}
	case 2528:
	{
		returnValue = F("Vor dem Hohen Stein");
		break;
	}
	case 2529:
	{
		returnValue = F("Vor dem Kranzenberg");
		break;
	}
	case 2530:
	{
		returnValue = F("Vor dem Stachenrod");
		break;
	}
	case 2531:
	{
		returnValue = F("Vor dem Weingarten");
		break;
	}
	case 2532:
	{
		returnValue = F("Vor den Bergäckern");
		break;
	}
	case 2533:
	{
		returnValue = F("Vor den Betten");
		break;
	}
	case 2534:
	{
		returnValue = F("Vor den Obergärten");
		break;
	}
	case 2535:
	{
		returnValue = F("Vor der Höhe");
		break;
	}
	case 2536:
	{
		returnValue = F("Vordere Ruh");
		break;
	}
	case 2537:
	{
		returnValue = F("Vordergasse");
		break;
	}
	case 2538:
	{
		returnValue = F("Vorn auf der Rothell");
		break;
	}
	case 2539:
	{
		returnValue = F("Vorstadt");
		break;
	}
	case 2540:
	{
		returnValue = F("Waagengasse");
		break;
	}
	case 2541:
	{
		returnValue = F("Wacholderbusch");
		break;
	}
	case 2542:
	{
		returnValue = F("Wacholderweg");
		break;
	}
	case 2543:
	{
		returnValue = F("Wächterspfad");
		break;
	}
	case 2544:
	{
		returnValue = F("Wäldchesgasse");
		break;
	}
	case 2545:
	{
		returnValue = F("Wagnerstraße");
		break;
	}
	case 2546:
	{
		returnValue = F("Wahnergasse");
		break;
	}
	case 2547:
	{
		returnValue = F("Waldbrunnenweg");
		break;
	}
	case 2548:
	{
		returnValue = F("Waldfrieden");
		break;
	}
	case 2549:
	{
		returnValue = F("Waldhausstraße");
		break;
	}
	case 2550:
	{
		returnValue = F("Waldhof");
		break;
	}
	case 2551:
	{
		returnValue = F("Waldstraße");
		break;
	}
	case 2552:
	{
		returnValue = F("Waldweg");
		break;
	}
	case 2553:
	{
		returnValue = F("Waldweide");
		break;
	}
	case 2554:
	{
		returnValue = F("Walkmühle");
		break;
	}
	case 2555:
	{
		returnValue = F("Walkweg");
		break;
	}
	case 2556:
	{
		returnValue = F("Wallstraße");
		break;
	}
	case 2557:
	{
		returnValue = F("Walltorstraße");
		break;
	}
	case 2558:
	{
		returnValue = F("Walpergasse");
		break;
	}
	case 2559:
	{
		returnValue = F("Walter-Süskind-Straße");
		break;
	}
	case 2560:
	{
		returnValue = F("Walther-Bender-Straße");
		break;
	}
	case 2561:
	{
		returnValue = F("Wanderslebener Straße");
		break;
	}
	case 2562:
	{
		returnValue = F("Wannhof");
		break;
	}
	case 2563:
	{
		returnValue = F("Warabistraße");
		break;
	}
	case 2564:
	{
		returnValue = F("Warthof");
		break;
	}
	case 2565:
	{
		returnValue = F("Wartweg");
		break;
	}
	case 2566:
	{
		returnValue = F("Washingtonstraße");
		break;
	}
	case 2567:
	{
		returnValue = F("Wassergasse");
		break;
	}
	case 2568:
	{
		returnValue = F("Wasserstraße");
		break;
	}
	case 2569:
	{
		returnValue = F("Watzenborner Straße");
		break;
	}
	case 2570:
	{
		returnValue = F("Watzenborner Weg");
		break;
	}
	case 2571:
	{
		returnValue = F("Wehlgarten");
		break;
	}
	case 2572:
	{
		returnValue = F("Wehrstraße");
		break;
	}
	case 2573:
	{
		returnValue = F("Weidegasse");
		break;
	}
	case 2574:
	{
		returnValue = F("Weidengasse");
		break;
	}
	case 2575:
	{
		returnValue = F("Weidenstraße");
		break;
	}
	case 2576:
	{
		returnValue = F("Weidenweg");
		break;
	}
	case 2577:
	{
		returnValue = F("Weidigstraße");
		break;
	}
	case 2578:
	{
		returnValue = F("Weidloh");
		break;
	}
	case 2579:
	{
		returnValue = F("Weigelstraße");
		break;
	}
	case 2580:
	{
		returnValue = F("Weiherhof");
		break;
	}
	case 2581:
	{
		returnValue = F("Weihersgärten");
		break;
	}
	case 2582:
	{
		returnValue = F("Weiherstraße");
		break;
	}
	case 2583:
	{
		returnValue = F("Weilburger Grenze");
		break;
	}
	case 2584:
	{
		returnValue = F("Weimarer Straße");
		break;
	}
	case 2585:
	{
		returnValue = F("Weinberggasse");
		break;
	}
	case 2586:
	{
		returnValue = F("Weinbergstraße");
		break;
	}
	case 2587:
	{
		returnValue = F("Weingartenstraße");
		break;
	}
	case 2588:
	{
		returnValue = F("Weinstraße");
		break;
	}
	case 2589:
	{
		returnValue = F("Weißenburgring");
		break;
	}
	case 2590:
	{
		returnValue = F("Weisserde");
		break;
	}
	case 2591:
	{
		returnValue = F("Weitershainer Straße");
		break;
	}
	case 2592:
	{
		returnValue = F("Welckerstraße");
		break;
	}
	case 2593:
	{
		returnValue = F("Wellersburgring");
		break;
	}
	case 2594:
	{
		returnValue = F("Wellerscheid");
		break;
	}
	case 2595:
	{
		returnValue = F("Wellhäuser Hof");
		break;
	}
	case 2596:
	{
		returnValue = F("Wermertshäuser Straße");
		break;
	}
	case 2597:
	{
		returnValue = F("Werner-von-Siemens-Straße");
		break;
	}
	case 2598:
	{
		returnValue = F("Werrastraße");
		break;
	}
	case 2599:
	{
		returnValue = F("Weserstraße");
		break;
	}
	case 2600:
	{
		returnValue = F("Westanlage");
		break;
	}
	case 2601:
	{
		returnValue = F("Westrain");
		break;
	}
	case 2602:
	{
		returnValue = F("Wettenberger Weg");
		break;
	}
	case 2603:
	{
		returnValue = F("Wettenbergring");
		break;
	}
	case 2604:
	{
		returnValue = F("Wetterauer Straße");
		break;
	}
	case 2605:
	{
		returnValue = F("Wetterfelder Straße");
		break;
	}
	case 2606:
	{
		returnValue = F("Wettergasse");
		break;
	}
	case 2607:
	{
		returnValue = F("Wetzlarer Hohl");
		break;
	}
	case 2608:
	{
		returnValue = F("Wetzlarer Straße");
		break;
	}
	case 2609:
	{
		returnValue = F("Wetzlarer Weg");
		break;
	}
	case 2610:
	{
		returnValue = F("Wetzsteinstraße");
		break;
	}
	case 2611:
	{
		returnValue = F("Wichernweg");
		break;
	}
	case 2612:
	{
		returnValue = F("Wickengartenstraße");
		break;
	}
	case 2613:
	{
		returnValue = F("Wieseckau");
		break;
	}
	case 2614:
	{
		returnValue = F("Wiesecker Weg");
		break;
	}
	case 2615:
	{
		returnValue = F("Wieseckstraße");
		break;
	}
	case 2616:
	{
		returnValue = F("Wiesenberger Ring");
		break;
	}
	case 2617:
	{
		returnValue = F("Wiesengrund");
		break;
	}
	case 2618:
	{
		returnValue = F("Wiesenhof");
		break;
	}
	case 2619:
	{
		returnValue = F("Wiesenstraße");
		break;
	}
	case 2620:
	{
		returnValue = F("Wiesenweg");
		break;
	}
	case 2621:
	{
		returnValue = F("Wiesstraße");
		break;
	}
	case 2622:
	{
		returnValue = F("Wildemannsgasse");
		break;
	}
	case 2623:
	{
		returnValue = F("Wildhof");
		break;
	}
	case 2624:
	{
		returnValue = F("Wilhelm-Hauff-Straße");
		break;
	}
	case 2625:
	{
		returnValue = F("Wilhelm-Jung-Straße");
		break;
	}
	case 2626:
	{
		returnValue = F("Wilhelm-Leuschner-Straße");
		break;
	}
	case 2627:
	{
		returnValue = F("Wilhelm-Leuschner-Weg");
		break;
	}
	case 2628:
	{
		returnValue = F("Wilhelm-Liebknecht-Straße");
		break;
	}
	case 2629:
	{
		returnValue = F("Wilhelm-Pfeiffer-Straße");
		break;
	}
	case 2630:
	{
		returnValue = F("Wilhelmshöhe");
		break;
	}
	case 2631:
	{
		returnValue = F("Wilhelmstraße");
		break;
	}
	case 2632:
	{
		returnValue = F("Willy-Brandt-Straße");
		break;
	}
	case 2633:
	{
		returnValue = F("Wilsonstraße");
		break;
	}
	case 2634:
	{
		returnValue = F("Winchester Straße");
		break;
	}
	case 2635:
	{
		returnValue = F("Winckelmannstraße");
		break;
	}
	case 2636:
	{
		returnValue = F("Windlücke");
		break;
	}
	case 2637:
	{
		returnValue = F("Wingert");
		break;
	}
	case 2638:
	{
		returnValue = F("Wingertberg");
		break;
	}
	case 2639:
	{
		returnValue = F("Wingertsberg");
		break;
	}
	case 2640:
	{
		returnValue = F("Wingertshecke");
		break;
	}
	case 2641:
	{
		returnValue = F("Wingertstraße");
		break;
	}
	case 2642:
	{
		returnValue = F("Wingertweg");
		break;
	}
	case 2643:
	{
		returnValue = F("Winner Höhe");
		break;
	}
	case 2644:
	{
		returnValue = F("Winneröder Straße");
		break;
	}
	case 2645:
	{
		returnValue = F("Wintergasse");
		break;
	}
	case 2646:
	{
		returnValue = F("Winterplatz");
		break;
	}
	case 2647:
	{
		returnValue = F("Wirberg");
		break;
	}
	case 2648:
	{
		returnValue = F("Wirberger Straße");
		break;
	}
	case 2649:
	{
		returnValue = F("Wirberger Weg");
		break;
	}
	case 2650:
	{
		returnValue = F("Wißmarer See");
		break;
	}
	case 2651:
	{
		returnValue = F("Wißmarer Straße");
		break;
	}
	case 2652:
	{
		returnValue = F("Wißmarer Weg");
		break;
	}
	case 2653:
	{
		returnValue = F("Wissmarer Weg");
		break;
	}
	case 2654:
	{
		returnValue = F("Wohnfelder Straße");
		break;
	}
	case 2655:
	{
		returnValue = F("Wohnpark Gullringen");
		break;
	}
	case 2656:
	{
		returnValue = F("Wolfskaute");
		break;
	}
	case 2657:
	{
		returnValue = F("Wolfstraße");
		break;
	}
	case 2658:
	{
		returnValue = F("Wolkengasse");
		break;
	}
	case 2659:
	{
		returnValue = F("Zahlgasse");
		break;
	}
	case 2660:
	{
		returnValue = F("Zeilstraße");
		break;
	}
	case 2661:
	{
		returnValue = F("Zelterstraße");
		break;
	}
	case 2662:
	{
		returnValue = F("Zeppelinstraße");
		break;
	}
	case 2663:
	{
		returnValue = F("Ziechhausweg");
		break;
	}
	case 2664:
	{
		returnValue = F("Ziegelberg");
		break;
	}
	case 2665:
	{
		returnValue = F("Ziegelgasse");
		break;
	}
	case 2666:
	{
		returnValue = F("Ziegelhütte");
		break;
	}
	case 2667:
	{
		returnValue = F("Ziegelhüttenweg");
		break;
	}
	case 2668:
	{
		returnValue = F("Ziegenhainer Straße");
		break;
	}
	case 2669:
	{
		returnValue = F("Zinzendorfweg");
		break;
	}
	case 2670:
	{
		returnValue = F("Zsambeker Straße");
		break;
	}
	case 2671:
	{
		returnValue = F("Zu den Kronwiesen");
		break;
	}
	case 2672:
	{
		returnValue = F("Zu den Linden");
		break;
	}
	case 2673:
	{
		returnValue = F("Zu den Mühlen");
		break;
	}
	case 2674:
	{
		returnValue = F("Zum Alten Born");
		break;
	}
	case 2675:
	{
		returnValue = F("Zum Bahnhof");
		break;
	}
	case 2676:
	{
		returnValue = F("Zum Bahnposten");
		break;
	}
	case 2677:
	{
		returnValue = F("Zum Biergraben");
		break;
	}
	case 2678:
	{
		returnValue = F("Zum Birgel");
		break;
	}
	case 2679:
	{
		returnValue = F("Zum Buchwald");
		break;
	}
	case 2680:
	{
		returnValue = F("Zum Dorffrieden");
		break;
	}
	case 2681:
	{
		returnValue = F("Zum Dorfplatz");
		break;
	}
	case 2682:
	{
		returnValue = F("Zum Eichenberg");
		break;
	}
	case 2683:
	{
		returnValue = F("Zum Fuchsstrauch");
		break;
	}
	case 2684:
	{
		returnValue = F("Zum Geiersberg");
		break;
	}
	case 2685:
	{
		returnValue = F("Zum Hardtwald");
		break;
	}
	case 2686:
	{
		returnValue = F("Zum Hasenberg");
		break;
	}
	case 2687:
	{
		returnValue = F("Zum Holzgraben");
		break;
	}
	case 2688:
	{
		returnValue = F("Zum Hoppenberg");
		break;
	}
	case 2689:
	{
		returnValue = F("Zum Klosterwald");
		break;
	}
	case 2690:
	{
		returnValue = F("Zum Kolbengraben");
		break;
	}
	case 2691:
	{
		returnValue = F("Zum Kreideberg");
		break;
	}
	case 2692:
	{
		returnValue = F("Zum Maiplatz");
		break;
	}
	case 2693:
	{
		returnValue = F("Zum Mönchacker");
		break;
	}
	case 2694:
	{
		returnValue = F("Zum Noll");
		break;
	}
	case 2695:
	{
		returnValue = F("Zum Ölberg");
		break;
	}
	case 2696:
	{
		returnValue = F("Zum Rosengarten");
		break;
	}
	case 2697:
	{
		returnValue = F("Zum Rotenberg");
		break;
	}
	case 2698:
	{
		returnValue = F("Zum Sandberg");
		break;
	}
	case 2699:
	{
		returnValue = F("Zum Schlegel");
		break;
	}
	case 2700:
	{
		returnValue = F("Zum Sportplatz");
		break;
	}
	case 2701:
	{
		returnValue = F("Zum Steinberg");
		break;
	}
	case 2702:
	{
		returnValue = F("Zum Stock");
		break;
	}
	case 2703:
	{
		returnValue = F("Zum Talblick");
		break;
	}
	case 2704:
	{
		returnValue = F("Zum Tiergärtner Teich");
		break;
	}
	case 2705:
	{
		returnValue = F("Zum Trinkbrunnen");
		break;
	}
	case 2706:
	{
		returnValue = F("Zum Waldsportplatz");
		break;
	}
	case 2707:
	{
		returnValue = F("Zum Weiher");
		break;
	}
	case 2708:
	{
		returnValue = F("Zum Weinberg");
		break;
	}
	case 2709:
	{
		returnValue = F("Zum Wiesengrund");
		break;
	}
	case 2710:
	{
		returnValue = F("Zum Wilsberg");
		break;
	}
	case 2711:
	{
		returnValue = F("Zum Windhöfchen");
		break;
	}
	case 2712:
	{
		returnValue = F("Zum Wingert");
		break;
	}
	case 2713:
	{
		returnValue = F("Zum Wingertsbaum");
		break;
	}
	case 2714:
	{
		returnValue = F("Zum Wirrgarten");
		break;
	}
	case 2715:
	{
		returnValue = F("Zum Zollstock");
		break;
	}
	case 2716:
	{
		returnValue = F("Zur Alten Eiche");
		break;
	}
	case 2717:
	{
		returnValue = F("Zur Arche");
		break;
	}
	case 2718:
	{
		returnValue = F("Zur Aue");
		break;
	}
	case 2719:
	{
		returnValue = F("Zur Burg");
		break;
	}
	case 2720:
	{
		returnValue = F("Zur Dreispitz");
		break;
	}
	case 2721:
	{
		returnValue = F("Zur Eiche");
		break;
	}
	case 2722:
	{
		returnValue = F("Zur Eichenhard");
		break;
	}
	case 2723:
	{
		returnValue = F("Zur Eichwiese");
		break;
	}
	case 2724:
	{
		returnValue = F("Zur Eisenbahn");
		break;
	}
	case 2725:
	{
		returnValue = F("Zur Eisenkaute");
		break;
	}
	case 2726:
	{
		returnValue = F("Zur Flur");
		break;
	}
	case 2727:
	{
		returnValue = F("Zur Fußmühle");
		break;
	}
	case 2728:
	{
		returnValue = F("Zur Gänsweide");
		break;
	}
	case 2729:
	{
		returnValue = F("Zur Grossen Bleiche");
		break;
	}
	case 2730:
	{
		returnValue = F("Zur Hofhell");
		break;
	}
	case 2731:
	{
		returnValue = F("Zur Hofstatt");
		break;
	}
	case 2732:
	{
		returnValue = F("Zur Jahneiche");
		break;
	}
	case 2733:
	{
		returnValue = F("Zur Kastanie");
		break;
	}
	case 2734:
	{
		returnValue = F("Zur Kreuzburg");
		break;
	}
	case 2735:
	{
		returnValue = F("Zur Langwiese");
		break;
	}
	case 2736:
	{
		returnValue = F("Zur Lutherlinde");
		break;
	}
	case 2737:
	{
		returnValue = F("Zur Mühle");
		break;
	}
	case 2738:
	{
		returnValue = F("Zur Müllerecke");
		break;
	}
	case 2739:
	{
		returnValue = F("Zur Napoleonsnase");
		break;
	}
	case 2740:
	{
		returnValue = F("Zur Platte");
		break;
	}
	case 2741:
	{
		returnValue = F("Zur Stadtmühle");
		break;
	}
	case 2742:
	{
		returnValue = F("Zur Vogelhecke");
		break;
	}
	case 2743:
	{
		returnValue = F("Zur Windmühle");
		break;
	}
	case 2744:
	{
		returnValue = F("Zur Ziegelhütte");
		break;
	}
	}
	return returnValue;
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