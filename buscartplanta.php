<?php
  include_once'./conexion.php'; 
    $conn = $mysqli;
      if($conn->connect_error){
        die("Conexión fallida: ".$conn->connect_error);
      }

    $salida = "";

    $query = "SELECT * FROM asistencia.docente where concat(idDocente,nomDoc,apepaDoc,apemaDoc,dni) like '%%';";

    if (isset($_POST['consulta'])) {
        $q = $conn->real_escape_string($_POST['consulta']);
        $query = "SELECT * FROM asistencia.docente where concat(idDocente,nomDoc,apepaDoc,apemaDoc,dni) like '%$q%';";
    }

    $resultado = $conn->query($query);


    if ($resultado->num_rows>0) {
       

        $salida.="<table  border='1'>
                <thead>
                    <tr id='titulo'bgcolor='#FF0000'>
                        <td>Codigo</td>
                        <td>Apellidos y Nombres</td>
                        <td>DNI</td>
                        <td>Estado</td>
                        <td>Detalles</td>
                        <td>Editar</td>
                    </tr>

                </thead>
                

        <tbody>";

        while ($fila = $resultado->fetch_array()) {
              if($fila[6]==1){
    $estado="Activo";
 }else {$estado="Inactivo";}

            $salida.="<tr>
                        <td>".$fila[0]."</td>
                        <td>".$fila[2]." ".$fila[3]." ".$fila[1]."</td>
                        <td>".$fila[4]."</td>
                        <td>".$estado."</td>
                        <td><a href='dtplanta.php?cod=".$fila[0]."' ><img src='images/deta.png' width='30' height='30'></a></td>
                        <td><a href='mtplanta.php?cod=".$fila[0]."' ><img src='images/edit.jpg' width='40' height='40'></a></td></tr>";

        }
        $salida.="</tbody></table>";
    }else{
        $salida.="NO HAY DATOS :(";
    }


    echo $salida;

    $conn->close();



?>