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
                        <h3 class="text-capitalize mb-4 text-center">REGISTRANDO INSUMO</h3>
                        <form action="control/cinsumo.php" method="post">
                            
                             <h5>CODIGO DE PLANTA<font color="red">*</font>:</h5>
                             <div class="input-group mt-3">
                                <input type="text" name=" tcod" class="form-control" placeholder="Ingrese Codigo" required="" readonly="" value="AUTOGENERADO">
                               
                            </div>

                            <h5>NOMBRE DE PLANTA<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="text" name=" tnom" class="form-control" placeholder="Ingrese Nombre de la Insumo" required="" value="">
                                
                            </div>
                         
                            <div class="input-group1 mt-3">
                                <button class="submit btn form-control" value="R" name="baccion">REGISTRAR</button>
                            <a href="insumo.php"><button type="button" class="btn btn form-control">ATRAS</button></a> 
                            </div>

                        </form>
                        
                    </div>

            

        </div>
   
 
</body>

</html>