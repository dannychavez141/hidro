<?php
  include_once'./conexion.php'; 
    $conn = $mysqli;
      if($conn->connect_error){
        die("Conexión fallida: ".$conn->connect_error);
      }

    $salida = "";

    $query = "SELECT p.idplantas,p.descr,p.idtplanta,tp.descr,tp.hum,tp.temp,tp.triego FROM hidroponia.plantas p join tplanta tp on p.idtplanta=tp.idtplanta 
where concat(p.idplantas,p.descr,tp.descr) like '%%';";

    if (isset($_POST['consulta'])) {
        $q = $conn->real_escape_string($_POST['consulta']);
        $query = "SELECT p.idplantas,p.descr,p.idtplanta,tp.descr,tp.hum,tp.temp,tp.triego FROM hidroponia.plantas p join tplanta tp on p.idtplanta=tp.idtplanta 
where concat(p.idplantas,p.descr,tp.descr) like '%$q%';";
    }

    $resultado = $conn->query($query);


    if ($resultado->num_rows>0) {
       

        $salida.="<table  border='1'>
                <thead>
                    <tr id='titulo'bgcolor='#FF0000'>
                        <td>Codigo</td>
                        <td>Nombre de  Planta</td>
                        <td>Tipo de planta</td>
                        <td>Temperatura Adecuada</td>
                        <td>Humedad Adecuada</td>
                        <td>Tiempo de riego</td>
                        <td>Editar</td>
                    </tr>
                </thead>
        <tbody>";

        while ($fila = $resultado->fetch_array()) {

            $salida.="<tr>
                        <td align='center'>".$fila[0]."</td>
                        <td align='center'>".$fila[1]."</td>
                        <td align='center'>".$fila[3]."</td>
                        <td align='center'>".$fila[5]."°C</td>
                        <td align='center'>".$fila[4]."%</td>
                        <td align='center'>".$fila[6]."seg</td>
                        <td align='center'><a href='mplanta.php?cod=".$fila[0]."' ><img src='images/edit.jpg' width='40' height='40'></a></td></tr>";

        }
        $salida.="</tbody></table>";
    }else{
        $salida.="NO HAY DATOS :(";
    }


    echo $salida;

    $conn->close();



?>