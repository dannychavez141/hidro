<?php
error_reporting(0);
require 'conexion.php';
$accion = $_POST['baccion'];
    echo "go?".$accion;
    switch ($accion) {
     case 'R':
       $tdescr = $_POST['tdescr'];
       $thora = $_POST['thora'];
         
        $sql="INSERT INTO `hidroponia`.`horas` (`descr`, `hora`) VALUES ('$tdescr', '$thora');";
        echo $sql;
    $rs=$mysqli->query($sql);
      
      header("Location: ../hora.php?tconf=true");
        exit;
            break;

    	case 'M':
      $tcod = $_POST['tcod'];
      $tdescr = $_POST['tdescr'];
       $thora = $_POST['thora'];
     $sql="UPDATE `hidroponia`.`horas` SET `descr`='$tdescr', `hora`='$thora' WHERE `idhoras`='$tcod';";
        echo $sql;
      $rs=$mysqli->query($sql);
       header("Location: ../hora.php?tconf=true");
       exit;
            break;
    	default:
    		# code...
    		break;
    }


?>