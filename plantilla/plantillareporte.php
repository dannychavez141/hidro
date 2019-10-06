<?php
	require 'fpdf/fpdf.php';
	
	class PDF extends FPDF
	{
		function Header()
		{ //Put the watermark
    //$this->Image('img/marca.png','0','0','200','300','PNG');
		//	$this->Image('img/escudo.jpg', 10, 10, 30 );
			//$this->Image('img/logo.png', 165, 10, 35 );
			$this->SetFont('Arial','BU',15);
			$this->Ln(20);
			$this->SetX(45);
			$this->Cell(120,10, 'REPORTE DE HIDROPONIA',0,0,'C');
			$this->Ln(15);
		


		}

	

		function Footer()
		{
			$this->SetY(-15);
			$this->SetFont('Arial','I', 8);
			$this->Cell(0,10, 'Pagina '.$this->PageNo().'/{nb}',0,0,'C' );
		}		
	}
?>