
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
                        <form action="control/cjardin.php" method="post">
                             <h5>CODIGO DE JARDIN<font color="red">*</font>:      AUTOGENERADO</h5>
                            </div>
                            <h5>SELECCIONE EL TIPO DE PLANTA<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
<?php $query = "SELECT * FROM hidroponia.plantas where concat(idplantas,descr) like '%%';";

    $resultado = $conn->query($query); ?>
                               <select class="form-control" name="plan" >
                                <?php   while ($fila = $resultado->fetch_array()) {?>
                                <option value="<?php echo $fila[0] ?>"><?php echo $fila[1] ?></option>
                            <?php } ?>
                              </select>
                            </div>
                            <h5>SELECCIONE HORARIO DE RIEGO<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
<table class="table"><tr>
  <td><div> <H5>MAÑANA</H5>
    <input type="radio" name="man" value="0" checked>NO RIEGO<br>
 <input type="radio" name="man" value="1">5:00 AM<br>
  <input type="radio" name="man" value="2">6:00 AM<br>
  <input type="radio" name="man" value="3">7:00 AM <br>
<input type="radio" name="man" value="4">8:00 AM <br>
<input type="radio" name="man" value="5">9:00 AM <br></div></td>
  <td><div> <H5>MERIDIANO</H5>  
    <input type="radio" name="med" value="0" checked>NO RIEGO<br>
 <input type="radio" name="med" value="6">11:00 AM<br>
  <input type="radio" name="med" value="7">12:00 AM<br>
  <input type="radio" name="med" value="8">1:00 PM <br>
<input type="radio" name="med" value="9">2:00 PM<br>
<input type="radio" name="med" value="10">3:00 PM<br></div></td>
  <td><div><H5>TARDE</H5>  
    <input type="radio" name="tar" value="0" checked>NO RIEGO<br>
  <input type="radio" name="tar" value="11">5:00 PM<br>
  <input type="radio" name="tar" value="12">6:00 PM<br>
  <input type="radio" name="tar" value="13">7:00 PM <br>
<input type="radio" name="tar" value="14">8:00 PM<br>
<input type="radio" name="tar" value="15">9:00 PM<br></div></td></tr></table>

                            </div>
                            <div class="input-group mt-3">
<table class="table"><tr>
  <td><div> <H5>SELECCIONAR INSUMOS:</H5><br>
    <?php $query = "SELECT * FROM hidroponia.insumos;";

    $resultado = $conn->query($query);
while ($fila = $resultado->fetch_array()) {
         ?>
     <label><input type="checkbox" name="ins[]" value="<?php echo $fila[0]?>"><?php echo ' '.$fila[1] ?></label><br> 
     <?php } ?> 
   </div></td>
 </tr></table>
                     
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