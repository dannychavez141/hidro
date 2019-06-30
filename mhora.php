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
                        <h3 class="text-capitalize mb-4 text-center">MODIFICANDO HORA</h3>
                        <form action="control/chora.php" method="post">
                            <?php $query = "SELECT * FROM hidroponia.horas where idhoras=$cod;";

    $planta = $conn->query($query); 
 while ($row = $planta->fetch_array()) {$hora=substr($row[2],0,5); echo $hora;
    ?>
                             <h5>CODIGO HORA<font color="red">*</font>:</h5>
                             <div class="input-group mt-3">
                                <input type="text" name=" tcod" class="form-control" placeholder="Ingrese Codigo" required="" readonly="" value=" <?php echo $row[0]?>">
                               
                            </div>

                            <h5>DESCRIPCION<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="text" name=" tdescr" class="form-control" placeholder="descripcion" required="" value=" <?php echo $row[1]?>">
                                
                            </div>
                         
                         <h5>HORA<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="time" name=" thora" value="<?php echo $hora?>" class="form-control" required="" >
                                
                            </div>
 
                            <div class="input-group1 mt-3">
                                <button class="submit btn form-control" value="M" name="baccion">MODIFICAR</button>
                            <a href="hora.php"><button type="button" class="btn btn form-control">ATRAS</button></a> 
                            </div>

                        <?php } ?>
                        </form>
                        
                    </div>

            

        </div>
   
 
</body>

</html>