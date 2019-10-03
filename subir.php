<?php
error_reporting(0);
 include_once'./conexion.php'; 
 $humedad = $_GET['h'];
 $temp = $_GET['t'];
 $hsuelo1 = $_GET['h1'];
  $hsuelo2 = $_GET['h2'];
   $hsuelo3 = $_GET['h3'];
   $hu=($hsuelo1+$hsuelo3)/2;
$sql="INSERT INTO `hidroponia`.`reporte` (`hum`, `temp`, `hsuelo1`, `hsuelo2`, `hsuelo3`, `fecha`) VALUES ('$humedad','$temp','$hsuelo1','$hsuelo2','$hsuelo3',now());";

     echo $sql;
        $rs=$mysqli->query($sql);         
        $mysqli->close();
   header("Status: 301 Moved Permanently");
header("Location: http://192.168.100.9");
exit;

?>
htm