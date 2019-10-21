<!--
Author:W3layouts
Author URL: http://w3layouts.com
License: Creative Commons Attribution 3.0 Unported
License URL: http://creativecommons.org/licenses/by/3.0/
-->

<!DOCTYPE html>
<html lang="zxx">

<?php include_once'./conexion.php';
   $conn = $mysqli;
    ?> 
    
<head>
    <title>HIDROPONIA UNU COMPUTACION MOVIL 2019-I</title>
    <!-- Meta tag Keywords -->
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta charset="UTF-8" />
    <meta name="keywords" content="Responsive web template, Bootstrap Web Templates, Flat Web Templates, Android Compatible web template, Smartphone Compatible web template, free webdesigns for Nokia, Samsung, LG, SonyEricsson, Motorola web design" />
    <script>
        addEventListener("load", function() {
            setTimeout(hideURLbar, 0);
        }, false);

        function hideURLbar() {
            window.scrollTo(0, 1);
        }
    </script>
    <?php 
    $sql = "SELECT s.idsembrio,vhorafija(s.man),vhorafija(s.mer),vhorafija(s.tar),tp.triego FROM hidroponia.jardin s join plantas p on s.idplanta=p.idplantas 
join tplanta tp on p.idtplanta=tp.idtplanta";
    $jardin = $conn->query($sql);
    $cont="var cont=0;";
    $triego="";
    $llaves=0;
    while ($row = $jardin->fetch_array()) {
$horas[]="var hora".$row[0]."="."['".$row[1]."','".$row[2]."','".$row[3]."'];";
$cont=$cont."var est".$row[0]."='a';var cont".$row[0]."=0;var salto".$row[0].";";
$triego=$triego."var triego".$row[0]."=".$row[4].";";
$llaves++;
}
 ?>
    <script language="JavaScript"> 
        var dias=['DOMINGO','LUNES','MARTES','MIERCOLES','JUEVES','VIERNES','SABADO'];
        <?php echo $cont;?>
         <?php echo $triego;?>
        <?php foreach ($horas as $hor ) {
        echo $hor;
    } 
    ?>
function mueveReloj(){ 
    momentoActual = new Date() 
      dia=dias[momentoActual.getDay()]+' '+momentoActual.getDate()+'/'+momentoActual.getMonth()+'/'+ momentoActual.getFullYear()
      hora = momentoActual.getHours() 
      minuto = momentoActual.getMinutes() 
      segundo = momentoActual.getSeconds() 

      str_segundo = new String (segundo) 
      if (str_segundo.length == 1) 
         segundo = "0" + segundo 

      str_minuto = new String (minuto) 
      if (str_minuto.length == 1) 
         minuto = "0" + minuto 

      str_hora = new String (hora) 
      if (str_hora.length == 1) 
       { hora = "0" + hora }
    
     var hor=hora+":" + minuto + ":" + segundo;
     cont++;
<?php for ($i=1; $i <=$llaves; $i++) {
echo "hora".$i.".forEach(function(hora) {
    if (hora==hor) {cont".$i."=cont+2; est".$i."='b';
  salt".$i."= window.open('http://192.168.100.5?llave".$i."=ON', '_blank'); 
 
}
});
console.log(cont".$i."+':'+cont);
 if (est".$i."=='b') {
    if(cont==cont".$i.")
  {cont".$i."=cont+triego".$i."; est".$i."='c';
    salt".$i.".close();
}}
 if (est".$i."=='c') {
    if(cont==cont".$i.")
  {cont".$i."=cont+2; est".$i."='d';
   salt".$i."= window.open('http://192.168.100.5?llave".$i."=OFF', '_blank'); 
}}
if (est".$i."=='d') {
    if(cont==cont".$i.")
  {cont".$i."=0; 
  est".$i."='a';
    salt".$i.".close();
}}";
   
} ?>



 if (str_hora > 12) 
       { hora =hora -12;

  mon="PM";}else mon="AM";


      horaImprimible =dia+ " "+hora + ":" + minuto + ":" + segundo +" "+mon;

      document.form_reloj.reloj.value = horaImprimible 

      setTimeout("mueveReloj()",1000) 
} 
</script> 
    <!-- //Meta tag Keywords -->
    <!-- Custom-Files -->
    <link rel="stylesheet" href="css/bootstrap.css">
    <!-- Bootstrap-Core-CSS -->
    <link rel="stylesheet" href="css/style.css" type="text/css" media="all" />
    <!-- Style-CSS -->
    <!-- font-awesome-icons -->
    <link href="css/font-awesome.css" rel="stylesheet">
    <!-- //font-awesome-icons -->
    <!-- /Fonts -->
    <link href="//fonts.googleapis.com/css?family=Poppins:100,100i,200,200i,300,300i,400,400i,500,500i,600,600i,700,700i,800" rel="stylesheet">
    <!-- //Fonts -->

</head>

<body onload="mueveReloj()">
    <!-- header -->
    <header id="home">
        <!-- top-bar -->
        <div class="top-bar py-2">
            <div class="container">
                <div class="row">
                    <div class="col-xl-6 col-lg-5 top-social-w3pvt-am mt-lg-1 mb-md-0 mb-1 text-lg-left text-center">
                        <div class="row">
                            <div class="col-xl-4 col-6 header-top_w3layouts border-right">
                                <p>
                                    <span class="fa fa-map-marker mr-2"></span>UNU, PUCALLPA
                                </p>
                            </div>
                            <div class="col-xl-4 col-6 header-top_w3layouts text-md-right">
                                <p class="text-bl">Hora del sistema
                                    <form name="form_reloj"> 
<input type="text" name="reloj" size="40" style="background-color : Black; color : White; font-family : Verdana, Arial, Helvetica; font-size : 8pt; text-align : center;" onfocus="window.document.form_reloj.reloj.blur()"> 
</form> 
                                </p>
                            </div>
                            <div class="col-xl-4"></div>
                        </div>
                    </div>
                    <div class="col-xl-6 col-lg-7 top-social-w3pvt-am mt-lg-0 mt-2">
                        <div class="row">
                            <div class="col-sm-6 top-w3layouts">
                                <div class="select-city text-center">
                                   
                                    <div class="clearfix"></div>
                                </div>
                            </div>
                            <div class="col-sm-6 border-left mt-lg-1 socila-brek text-md-right text-center">
                               
                                <!-- //social icons -->
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </header>
    <!-- //top-bar -->

    <!-- header 2 -->
    <!-- navigation -->
    <div class="main-top">
        <div class="container d-lg-flex">
            <!-- logo -->
            <h1 class="logo-w3pvt float-left">
                <a class="navbar-brand" href="index.php">
                    <img src="images/logounu.jpg" class="img-fluid logo-img" width="50" >HIDROPONIA UNU
                </a>
            </h1>
            <!-- //logo -->
            <!-- nav -->
            <div class="nav_w3pvt mx-lg-auto">
                <nav>
                    <label for="drop" class="toggle">Menu</label>
                    <input type="checkbox" id="drop" />
                    <ul class="menu mx-lg-auto">
                        <li><a href="index.php" class="active">INICIO</a></li>
                        <li><a href="planta.php">PLANTAS</a></li>
                        <li><a href="insumo.php">INSUMOS</a></li>
                     
                        <li>
                            <!-- First Tier Drop Down -->
                            <label for="drop-2" class="toggle toogle-2">SISTEMA<span class="fa fa-angle-down" aria-hidden="true"></span>
                            </label>
                            <a href="#">SISTEMA<span class="fa fa-angle-down" aria-hidden="true"></span></a>
                            <input type="checkbox" id="drop-2" />
                            <ul>
                              <!--  <li><a href="http://192.168.100.5" class="drop-text"  target="_blank">RIEGO</a></li>-->
                                <li><a href="rvirtual.php" class="drop-text">ESTADISTICAS</a></li>
                                <li><a href="tplanta.php" class="drop-text">TIPO DE PLANTAS</a></li>
                                <li><a href="jardines.php" class="drop-text">JARDINES</a></li>
                                <li><a href="hora.php" class="drop-text">HORAS</a></li>
                                <li><a href="reporte.php" class="drop-text">REPORTES</a></li>
                                <li><a href="usuario.php" class="drop-text">USUARIOS</a></li>
                            </ul>
                        </li>
                   
                           
                    </ul>
                </nav>
            </div>
            <!-- //nav -->
            <!-- dwn -->
            <div class="free-w3pvt text-center">
                <a href="#contact" class="login-button-2 text-uppercase scroll mt-lg-0 mt-2">
                    ACCEDER AL SISTEMA 
                </a>
            </div>
            <!-- //dwn -->
        </div>
    </div>
    <!-- //navigation -->

</body>
</html>