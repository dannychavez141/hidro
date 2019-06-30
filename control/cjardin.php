<?php
error_reporting(0);
require 'conexion.php';
    $conn = $mysqli;
$accion = $_POST['baccion'];
    echo "go?".$accion.'<br>';
    switch ($accion) {
     case 'R':
         $plan = $_POST['plan'];
          $man = $_POST['man'];
           $med = $_POST['med'];
            $tar = $_POST['tar'];
             $query = "SELECT count(idsembrio)+1 FROM hidroponia.jardin;";
       $resultado = $conn->query($query);

while ($fila = $resultado->fetch_array()) {
$jar=$fila[0];

}
$sql="INSERT INTO `hidroponia`.`jardin` (`idplanta`, `fecha`, `man`, `mer`, `tar`) VALUES ('$plan',now(),'$man','$med','$tar');";
echo $sql;
 $rs=$mysqli->query($sql);
foreach($_POST['ins'] as $seleccion) {
$sql="INSERT INTO `hidroponia`.`jardin_insumo` (`idjardin`, `idinsumo`, `cant`) VALUES ('$jar', '$seleccion', '100');";
    echo $sql;
     $rs=$mysqli->query($sql);
}
 header("Location: ../jardines.php?tconf=true");
     exit;
            break;
    	case 'M':
        $cod = $_POST['cod'];
      $plan = $_POST['plan'];
          $man = $_POST['man'];
           $med = $_POST['med'];
            $tar = $_POST['tar'];
$sql="UPDATE `hidroponia`.`jardin` SET `idplanta`='$plan', `fecha`= now(), `man`='$man', `mer`='$med', `tar`='$tar' WHERE `idsembrio`='$cod';";
      $rs=$mysqli->query($sql);
      echo $sql;
     $sql="DELETE FROM `hidroponia`.`jardin_insumo`
WHERE idjardin=$cod;";
echo $sql;
      $rs=$mysqli->query($sql);
foreach($_POST['ins'] as $seleccion) {
$sql="INSERT INTO `hidroponia`.`jardin_insumo` (`idjardin`, `idinsumo`, `cant`) VALUES ('$cod', '$seleccion', '100');";
    echo $sql;
     $rs=$mysqli->query($sql);
}

header("Location: ../jardines.php?tconf=true");
       exit;
            break;
    	default:
    		# code...
    		break;
    }


?>