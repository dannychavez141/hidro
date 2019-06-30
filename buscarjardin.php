<?php
  include_once'./conexion.php'; 
    $conn = $mysqli;
      if($conn->connect_error){
        die("Conexión fallida: ".$conn->connect_error);
      }

    $salida = "";

    $query = "SELECT * FROM hidroponia.jardin s join plantas p on s.idplanta=p.idplantas where concat(s.idsembrio,p.descr) like'%%'";

    if (isset($_POST['consulta'])) {
        $q = $conn->real_escape_string($_POST['consulta']);
        $query = "SELECT * FROM hidroponia.jardin s join plantas p on s.idplanta=p.idplantas where concat(s.idsembrio,p.descr) like'%$q%';";
    }

    $resultado = $conn->query($query);


    if ($resultado->num_rows>0) {
       

        $salida.="<table  border='1'>
                <thead>
                    <tr id='titulo'bgcolor='#FF0000'>
                        <td>N° de LLave</td>
                        <td>Nombre de  Planta</td>
                        <td>Fecha de Plantacion</td>
                        <td>Ver Riego</td>
                        <td>Editar</td>
                    </tr>
                </thead>
        <tbody>";

        while ($fila = $resultado->fetch_array()) {

            $salida.="<tr>
                        <td align='center'>".$fila[0]."</td>
                        <td align='center'>".$fila[7]."</td>
                        <td align='center'>".$fila[2]."</td>
                        <td align='center'><a href='djardin.php?cod=".$fila[0]."' ><img src='images/riego.jpg' width='40' height='40'></a></td>
                        <td align='center'><a href='mjardin.php?cod=".$fila[0]."' ><img src='images/edit.jpg' width='40' height='40'></a></td></tr>";

        }
        $salida.="</tbody></table>";
    }else{
        $salida.="NO HAY DATOS :(";
    }


    echo $salida;

    $conn->close();



?>