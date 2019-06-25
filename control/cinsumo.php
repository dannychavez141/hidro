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
      
      header("Location: ../insumo.php?tconf=true");
        exit;
            break;

    	case 'M':
      $tcod = $_POST['tcod'];
      $tnom = $_POST['tnom'];
     $sql="UPDATE `hidroponia`.`insumos` SET `descr`='$tnom' WHERE `idinsumos`='$tcod';";
        echo $sql;
      $rs=$mysqli->query($sql);
       header("Location: ../insumo.php?tconf=true");
       exit;
            break;
    	default:
    		# code...
    		break;
    }


?>