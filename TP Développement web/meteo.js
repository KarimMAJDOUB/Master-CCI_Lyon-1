var Lyon = document.getElementById("LyonBlock");
      var Saintetienne = document.getElementById("SaintetienneBlock");
      var Grenoble = document.getElementById("GrenobleBlock");
      var Dijon = document.getElementById("DijonBlock");
      var Auxerre = document.getElementById("AuxerreBlock");
      var Dole = document.getElementById("DoleBlock");
      var Rennes = document.getElementById("RennesBlock");
      var Brest = document.getElementById("BrestBlock");
      var Lorient = document.getElementById("LorientBlock");
      var Bordeaux = document.getElementById("BordeauxBlock");
      var Pau = document.getElementById("PauBlock");
      var Bayonnes = document.getElementById("BayonnesBlock");
      var France = document.getElementById("FranceBlock");
      var Regions = document.getElementById("RegionsBlock");
      
      function showCity()
      {
      
      var region = document.getElementById("regions").value;
      var ville = document.getElementById("villes").value;
      var pay = document.getElementById("pays").value;
       let villeCourante = document.getElementById("villes").value;
      
      if(pay == "France" & region=="selection" & ville == "selection")
      {
      document.getElementById("regions").style.visibility ="visible";
      
      France.style.visibility = "visible";
      
      Regions.style.visibility = "visible";
      
      }
      
      
      else if(pay == "France" & region=="Auvergne-Rhône-Alpes" & ville == "selection")
      {
      document.getElementById("villes").style.visibility ="visible";
      
      Lyon.style.visibility = "visible";
      Saintetienne.style.visibility = "visible";
      Grenoble.style.visibility = "visible";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      }
      else if(pay == "France" & region=="Auvergne-Rhône-Alpes" & ville == "Lyon")
      {
      
      Lyon.style.visibility = "visible";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      
      
      } 
       else if(pay == "France" & region=="Auvergne-Rhône-Alpes" & ville == "Saintetienne")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "visible";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      } 
      
      else if(pay == "France" & region=="Auvergne-Rhône-Alpes" & ville == "Grenoble")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "visible";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      
      }
          else if(pay == "France" & region=="Bourgogne-Franche-Comté" & ville == "selection")
      {
      document.getElementById("villes").style.visibility ="visible";
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "visible";
      Auxerre.style.visibility = "visible";
      Dole.style.visibility = "visible";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      }
      
      else if(pay == "France" & region=="Bourgogne-Franche-Comté" & ville == "Dijon")
      {
      
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "visible";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      }
      
      else if(pay == "France" & region=="Bourgogne-Franche-Comté" & ville == "Auxerre")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "visible";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      }
      else if(pay == "France" & region=="Bourgogne-Franche-Comté" & ville == "Dole")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "visible";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      }
      
      else if(pay == "France" & region=="Bretagne" & ville == "selection")
      {
      document.getElementById("villes").style.visibility ="visible";
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "visible";
      Brest.style.visibility = "visible";
      Lorient.style.visibility = "visible";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      }
      
      else if(pay == "France" & region=="Bretagne" & ville == "Rennes")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "visible";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      }
      else if(pay == "France" & region=="Bretagne" & ville == "Brest")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "visible";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      }
      else if(pay == "France" & region=="Bretagne" & ville == "Lorient")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "visible";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      }
      
      else if(pay == "France" & region=="Aquitaine" & ville == "selection")
      {
      document.getElementById("villes").style.visibility ="visible";
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "visible";
      Pau.style.visibility = "visible";
      Bayonnes.style.visibility = "visible";
      
      }
      
      else if(pay == "France" & region=="Aquitaine" & ville == "Bordeaux")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "visible";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "hidden";
      
      }
      
      else if(pay == "France" & region=="Aquitaine" & ville == "Pau")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "visible";
      Bayonnes.style.visibility = "hidden";
      
      }
      
      else if(pay == "France" & region=="Aquitaine" & ville == "Bayonnes")
      {
      Lyon.style.visibility = "hidden";
      Saintetienne.style.visibility = "hidden";
      Grenoble.style.visibility = "hidden";
      Dijon.style.visibility = "hidden";
      Auxerre.style.visibility = "hidden";
      Dole.style.visibility = "hidden";
      Rennes.style.visibility = "hidden";
      Brest.style.visibility = "hidden";
      Lorient.style.visibility = "hidden";
      Bordeaux.style.visibility = "hidden";
      Pau.style.visibility = "hidden";
      Bayonnes.style.visibility = "visible";
      
      }
      }