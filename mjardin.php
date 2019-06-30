
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
                        <h3 class="text-capitalize mb-4 text-center">MODIFICANDO JARDIN</h3>
                        <form action="control/cjardin.php" method="post">
                          <?php $sql = "SELECT s.idsembrio,s.idplanta,p.descr,s.fecha,s.man,vhora(s.man),s.mer,vhora(s.mer),s.tar,vhora(s.tar) FROM hidroponia.jardin s join plantas p on s.idplanta=p.idplantas where s.idsembrio=$cod";

    $jardin = $conn->query($sql); while ($row = $jardin->fetch_array()) {?> 


                             <h5>N° DE JARDIN<font color="red">*</font>:  <input type="text" name="cod" value="<?php echo $row[0] ?>" readonly> </h5>
                            </div>
                            <h5>SELECCIONE EL TIPO DE PLANTA<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
<?php $query = "SELECT * FROM hidroponia.plantas where concat(idplantas,descr) like '%%';";

    $resultado = $conn->query($query); ?>
                               <select class="form-control" name="plan" >
                                 <option value="<?php echo $row[1] ?>"><?php echo $row[3] ?></option>
                                <?php   while ($fila = $resultado->fetch_array()) {?>
                                <option value="<?php echo $fila[0] ?>"><?php echo $fila[1] ?></option>
                            <?php } ?>
                              </select>
                            </div>
                            <h5>SELECCIONE HORARIO DE RIEGO<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
<table class="table"><tr>
  <td><div> <H5>MAÑANA</H5>
    <?php if ($row[4]==0) {?>
     <input type="radio" name="man" value="0" checked>NO RIEGO<br>
     
   <?php }else{ ?>
    <input type="radio" name="man" value="<?php echo $row[4] ?>" checked><?php echo $row[5]  ?><br>
  <?php } ?>
    <input type="radio" name="man" value="0">NO RIEGO<br>
 <input type="radio" name="man" value="1">5:00 AM<br>
  <input type="radio" name="man" value="2">6:00 AM<br>
  <input type="radio" name="man" value="3">7:00 AM <br>
<input type="radio" name="man" value="4">8:00 AM <br>
<input type="radio" name="man" value="5">9:00 AM <br></div></td>
  <td><div> <H5>MERIDIANO</H5>  
    <?php if ($row[6]==0) {?>
     <input type="radio" name="med" value="0" checked>NO RIEGO<br>
   <?php }else{ ?>
    <input type="radio" name="med" value="<?php echo $row[6] ?>" checked><?php echo $row[7]  ?><br>
  <?php } ?>
    <input type="radio" name="med" value="0" >NO RIEGO<br>
 <input type="radio" name="med" value="6">11:00 AM<br>
  <input type="radio" name="med" value="7">12:00 AM<br>
  <input type="radio" name="med" value="8">1:00 PM <br>
<input type="radio" name="med" value="9">2:00 PM<br>
<input type="radio" name="med" value="10">3:00 PM<br></div></td>
  <td><div><H5>TARDE</H5>  
    <?php if ($row[8]==0) {?>
     <input type="radio" name="tar" value="0" checked>NO RIEGO<br>
   <?php }else{ ?>
    <input type="radio" name="tar" value="<?php echo $row[8] ?>" checked><?php echo $row[9]  ?><br>
  <?php } ?>
    <input type="radio" name="tar" value="0">NO RIEGO<br>
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
while ($fila = $resultado->fetch_array()) {$est='';
  $insumo = "SELECT * FROM hidroponia.jardin_insumo where idjardin=$cod;";
  $insumos = $conn->query($insumo);
while ($lista = $insumos->fetch_array()) {
  
  if($lista[2]==$fila[0]){$est='checked';}
}
         ?>
     <label><input type="checkbox" name="ins[]" value="<?php echo $fila[0]?>" <?php echo $est ?>><?php echo ' '.$fila[1] ?></label><br> 
    
     <?php } ?> 
   </div></td>
 </tr></table>
                     
</div>
<div class="input-group1 mt-3">
                                <button class="submit btn form-control" value="M" name="baccion">MODIFICAR</button>
                                <a href="planta.php"><button type="button" class="btn btn form-control">ATRAS</button></a> 
                            </div>
                       <?php } ?> </form>
                    </div>

            

        </div>
   
 
</body>

</html>