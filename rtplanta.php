
<!DOCTYPE html>
<html lang="zxx">
<?php error_reporting(0);
 include_once'./cabezera.php';  ?>


<body>
   
    
        <div class="container-fluid py-md-5 inner-sec-w3ls">
          
                    <div class="form">
                        <h3 class="text-capitalize mb-4 text-center">REGISTRANDO TIPO DE PLANTA</h3>
                        <form action="#" method="post">
                             <h5>CODIGO DE TIPO PLANTA<font color="red"></font>:      AUTOGENERADO</h5>
<br>
                            <h5>NOMBRE DE TIPO PLANTA<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="text" name=" tplant" class="form-control" placeholder="Ingrese Nombre de la Planta" required="">
                                
                            </div>
<h5>TEMPERATURA ADECIADA C°<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="text" name="ttemp" class="form-control" placeholder="Ingrese Temperatura" required=""></div>
                                <h5>HUMEDAD ADECUADA %<font color="red">*</font>:</h5>
                            <div class="input-group mt-3">
                                <input type="text" name="thum" class="form-control" placeholder="Ingrese Humedad" required=""></div>


                            <h5>SELECCIONE HORAS DE RIEGO<font color="red">*</font>:</h5>
                           
                            <h5>8am<input type="checkbox" name="chor" value="1" checked="checked"></input ></h5> 
                            <h5>8am<input type="checkbox" name="chor" value="1" ></input ></h5>  
                         
                         
 
                            <div class="input-group1 mt-3">
                                <button class="submit btn form-control">REGISTRAR</button>
                            </div>
                        </form>
                    </div>

            

        </div>
   
 
</body>

</html>