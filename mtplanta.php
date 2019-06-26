
<!DOCTYPE html>
<html lang="zxx">
<?php error_reporting(0);
 include_once'./cabezera.php';  
 include_once'./conexion.php';
   $conn = $mysqli;
$cod=$_GET['cod'];
?>


<body>
   
    
        <div class="container-fluid py-md-5 inner-sec-w3ls">
          
                    <div class="form">
                        <h3 class="text-capitalize mb-4 text-center">MODIFICANDO TIPO DE PLANTA</h3>
                        <form action="ctplanta.php" method="post">
                             
<?php $query = "SELECT * FROM hidroponia.tplanta where idtplanta=$cod;";

    $planta = $conn->query($query); 
 while ($row = $planta->fetch_array()) {
    ?>
                             <h5>CODIGO DE TIPO PLANTA<font color="red">*</font>:</h5>
                             <div class="input-group mt-3">
                                <input type="text" name="tcod" class="form-control" placeholder="Ingrese Codigo" required="" readonly="" value="<?php echo $row[0] ?>">
                                
                            </div>
<br>
                            <h5>NOMBRE DE TIPO PLANTA<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="text" name="tnom" class="form-control" placeholder="Ingrese Nombre de la Planta" required=""value="<?php echo $row[1] ?>">
                                
                            </div>
<h5>TEMPERATURA ADECIADA C°<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="text" name="ttemp" class="form-control" placeholder="Ingrese Temperatura" required="" value="<?php echo $row[2] ?>"></div>
                                <h5>HUMEDAD ADECUADA %<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="text" name="thum" class="form-control" placeholder="Ingrese Humedad" required="" value="<?php echo $row[3] ?>"></div>
                                <h5>TIEMPO DE RIEGO Seg<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="text" name="ttiem" class="form-control" placeholder="Ingrese Tiempo" required="" value="<?php echo $row[4] ?>"></div>

                            <div class="input-group1 mt-3">
                                <button class="submit btn form-control" value="M" name="baccion">MODIFICAR</button>
                            <a href="tplanta.php"><button type="button" class="btn btn form-control">ATRAS</button></a> 
                            </div>
                        <?php } ?>
                        </form>
                    </div>

            

        </div>
   
 
</body>

</html>