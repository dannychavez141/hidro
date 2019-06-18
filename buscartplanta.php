<?php
  include_once'./conexion.php'; 
    $conn = $mysqli;
      if($conn->connect_error){
        die("Conexión fallida: ".$conn->connect_error);
      }

    $salida = "";

    $query = "SELECT * FROM hidroponia.tplanta where concat(idtplanta,descr) like '%%';";

    if (isset($_POST['consulta'])) {
        $q = $conn->real_escape_string($_POST['consulta']);
        $query = "SELECT * FROM hidroponia.tplanta where concat(idtplanta,descr) like '%$q%';";
    }

    $resultado = $conn->query($query);


    if ($resultado->num_rows>0) {
       

        $salida.="<table  border='1'>
                <thead>
                    <tr id='titulo'bgcolor='#FF0000'>
                        <td>Codigo</td>
                        <td>Descripcion</td>
                        <td>Temperatura Adecuada</td>
                        <td>Humedad Adecuada</td>
                        
                        <td>Editar</td>
                    </tr>

                </thead>
                

        <tbody>";

        while ($fila = $resultado->fetch_array()) {
              

            $salida.="<tr>
                        <td align='center'>".$fila[0]."</td>
                        <td align='center'>".$fila[1]."</td>
                        <td align='center'>".$fila[2]."</td>
                        <td align='center'>".$fila[3]."</td>
                        <td align='center'><a href='mtplanta.php?cod=".$fila[0]."' ><img src='images/edit.jpg' width='40' height='40'></a></td></tr>";

        }
        $salida.="</tbody></table>";
    }else{
        $salida.="NO HAY DATOS :(";
    }


    echo $salida;

    $conn->close();



?>