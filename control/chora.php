<?php
error_reporting(0);
require 'conexion.php';
$accion = $_POST['baccion'];
    echo "go?".$accion;
    switch ($accion) {
     case 'R':
         $tnom = $_POST['tnom'];
         
        $sql="INSERT INTO `hidroponia`.`insumos` (`descr`) VALUES ('$tnom');";
        echo $sql;
    $rs=$mysqli->query($sql);
      
      header("Location: ../hora.php?tconf=true");
        exit;
            break;

    	case 'M':
      $tcod = $_POST['tcod'];
      $descr = $_POST['descr'];
       $hora = $_POST['hora'];
     $sql="UPDATE `hidroponia`.`insumos` SET `descr`='$tnom' WHERE `idinsumos`='$tcod';";
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