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
      
      header("Location: ../tplanta.php?tconf=true");
        exit;
            break;

    	case 'M':
        $tcod = $_POST['tcod'];
       $tnom = $_POST['tnom'];
         $ttem = $_POST['ttemp'];
         $thum = $_POST['thum'];
         $ttiem = $_POST['ttiem'];
     $sql="UPDATE `UPDATE `hidroponia`.`tplanta` SET `descr`='$tnom', `temp`='$ttem', `hum`='$thum ', `triego`='$ttiem' WHERE `idtplanta`='$tcod';";
        echo $sql;
      $rs=$mysqli->query($sql);
       header("Location: ../tplanta.php?tconf=true");
       exit;
            break;
    	default:
    		# code...
    		break;
    }


?>