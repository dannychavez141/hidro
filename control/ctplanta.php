<?php
error_reporting(0);
require 'conexion.php';
$accion = $_POST['baccion'];
    echo "go?".$accion;
    switch ($accion) {
     case 'R':
         $tnom = $_POST['tnom'];
         $ttem = $_POST['ttemp'];
         $thum = $_POST['thum'];
         $ttiem = $_POST['ttiem'];
          
        
          
        $sql="INSERT INTO `hidroponia`.`tplanta` (`descr`, `temp`, `hum`, `triego`) VALUES ('$tnom', '$ttem', '$thum', '$ttiem');";
        echo $sql;
    $rs=$mysqli->query($sql);
      
      header("Location: ../planta.php?tconf=true");
        exit;
            break;

    	case 'M':
        $tcod = $_POST['tcod'];
      $tnom = $_POST['tnom'];
          $tplan = $_POST['tplan'];
     $sql="UPDATE `hidroponia`.`plantas` SET `descr`='$tnom', `idtplanta`='$tplan' WHERE `idplantas`='$tcod';";
        echo $sql;
      $rs=$mysqli->query($sql);
       header("Location: ../planta.php?tconf=true");
       exit;
            break;
    	default:
    		# code...
    		break;
    }


?>