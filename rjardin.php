
<!DOCTYPE html>
<html lang="zxx">
<?php error_reporting(0);
 include_once'./cabezera.php'; 
  include_once'./conexion.php';
   $conn = $mysqli;
  ?>


<body>
   
    
        <div class="container-fluid py-md-5 inner-sec-w3ls">
          
                    <div class="form">
                        <h3 class="text-capitalize mb-4 text-center">REGISTRANDO JARDIN</h3>
                        <form action="control/cplanta.php" method="post">
                             <h5>CODIGO DE PLANTA<font color="red">*</font>:      AUTOGENERADO</h5>

                           
                            </div>
                            <h5>SELECCIONE EL TIPO DE PLANTA<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
<?php $query = "SELECT * FROM hidroponia.plantas where concat(idtplanta,descr) like '%%';";

    $resultado = $conn->query($query);

         ?>
                               <select class="form-control" name="tplan" >
                                <?php   while ($fila = $resultado->fetch_array()) {?>
                                <option value="<?php echo $fila[0] ?>"><?php echo $fila[1] ?></option>
                            <?php } ?>
                              </select>

                            </div>
                           
                            <div class="input-group1 mt-3">
                                <button class="submit btn form-control" value="R" name="baccion">REGISTRAR</button>
                                <a href="planta.php"><button type="button" class="btn btn form-control">ATRAS</button></a> 
                            </div>
                        </form>
                    </div>

            

        </div>
   
 
</body>

</html>