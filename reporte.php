
<!DOCTYPE html>
<html lang="zxx">
<?php error_reporting(0);
 include_once'./cabezera.php'; 
  $dia=date('d');
  //if ($dia<10) {
//   $dia='0'.$dia;
 // }
   $fecha=date('Y-m')."-".$dia;
  // echo $fecha;
  ?>


<body>
   
    
        <div class="container-fluid py-md-5 inner-sec-w3ls">
          
                    <div class="form">
                        <h3 class="text-capitalize mb-4 text-center">GENERANDO REPORTE DE ISLAS</h3>
                        <form action="pdfreporte.php" method="post" target="_blank">
                            

                            <h5>SELECCIONE ISLA:<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <select class="form-control" name="isla">
                                   <option value="1">ISLA 1</option>
                                   <option value="2">ISLA 2</option>
                                    <option value="3">ISLA 3</option> 
                                    <option value="0">TODAS LAS ISLAS</option>
                                </select>
                            </div>
                            <h5>FECHA INICIO:<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                              <input type="date"class="form-control" name="ini" max="<?php echo $fecha ?>" value="<?php echo $fecha ?>">
                            </div>
                            <h5>FECHA FIN:<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                              <input type="date"class="form-control" name="fin" max="<?php echo $fecha ?>" value="<?php echo $fecha ?>">
                            </div>
                            
                           
                            <div class="input-group1 mt-3">
                                <button class="submit btn form-control" value="R" name="baccion">GENERAR REPORTE</button>
                               
                            </div>

                        </form>
                    </div>

            

        </div>
   
 
</body>

</html>