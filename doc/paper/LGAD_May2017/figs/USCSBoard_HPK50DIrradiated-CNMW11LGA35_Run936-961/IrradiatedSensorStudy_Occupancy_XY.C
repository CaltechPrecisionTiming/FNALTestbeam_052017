void Make2DPlot_CNM() {

  TChain ch("pulse");
  ch.Add("/afs/cern.ch/work/s/sixie/public/releases/run2/Timing/CMSSW_9_0_2/src/FNALTestbeam_052017/Analysis/LGAD/data/RECO/V2/Run936-961_RECO_FINAL.root");
  TCanvas *c1 = new TCanvas("c1","multipads",700,600);
  c1->SetLeftMargin(0.13);
  c1->SetRightMargin(0.18);
  TH2F *h1 = new TH2F( "h1",";;;",40,15.175, 16.575,40,21.775,23.175);
  TH2F *hCount = new TH2F( "hCount",";;;",40,15.175, 16.575,40,21.775,23.175);

  gStyle->SetPalette(1); //kBird

  ch.Draw("y1/1000.:x1/1000.>>h1","1000*amp[2]*(x1/1000.>15.375&&x1/1000.<16.375&&y1/1000.>21.975&&y1/1000.<22.975)","colz");
  ch.Draw("y1/1000.:x1/1000.>>hCount","(x1/1000.>15.375&&x1/1000.<16.375&&y1/1000.>21.975&&y1/1000.<22.975)","colz");

  for( int i=1; i<h1->GetXaxis()->GetNbins()+1; i++) {
    for( int j=1; j<h1->GetYaxis()->GetNbins()+1; j++) {
      cout << i << " " << j << " : " << hCount->GetBinContent(i,j) << "\n";
      if (hCount->GetBinContent(i,j) > 0) {
	cout << i << " " << j << " : " << h1->GetBinContent(i,j) << " " << hCount->GetBinContent(i,j) << " : " << h1->GetBinContent(i,j) / hCount->GetBinContent(i,j) << "\n";
	h1->SetBinContent(i,j, h1->GetBinContent(i,j) / hCount->GetBinContent(i,j));
      }
    }
  }

  h1->SetStats(0);
  h1->SetTitle("");
  h1->GetZaxis()->SetRangeUser(0,100);
  h1->GetXaxis()->SetTitle("x-coordinate [mm]");
  h1->GetYaxis()->SetTitle("y-coordinate [mm]");
  h1->Draw("colz");
  h1->GetXaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.04);
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetYaxis()->SetLabelSize(0.04);
  h1->GetYaxis()->SetTitleOffset(1.2);
  h1->GetZaxis()->SetTitle("Mean Amplitude [mV]");
  h1->GetZaxis()->SetTitleSize(0.05);
  h1->GetZaxis()->SetTitleOffset(1.2);
  h1->GetZaxis()->SetLabelOffset(0.01);
  h1->GetZaxis()->SetLabelSize(0.04);
  h1->Draw("colz");


  TEllipse *el = new TEllipse(15.875,22.475,0.350,0.350);
  el->SetFillStyle(0);
  el->SetLineColor(kRed);
  el->SetLineWidth(8);
  el->Draw();
  TEllipse *el1 = new TEllipse(15.875,22.475,0.370,0.370);
  el1->SetFillStyle(0);
  el1->SetLineWidth(8);
  el1->SetLineColor(kBlack);
  el1->Draw();
  TBox *box = new TBox(15.375,21.975,16.375,22.975);
  box->SetFillStyle(0);
  box->SetLineWidth(8);
  box->SetLineColor(kBlack);
  box->Draw();

}


void Make1DPlot_CNM() {
  TChain ch("pulse");
  ch.Add("/afs/cern.ch/work/s/sixie/public/releases/run2/Timing/CMSSW_9_0_2/src/FNALTestbeam_052017/Analysis/LGAD/data/RECO/V2/Run936-961_RECO_FINAL.root");
  TCanvas *c1 = new TCanvas("c1","multipads",700,600);
  c1->SetLeftMargin(0.12);
  ch.Draw("amp[2]>>h1(75,0,0.5)","(x1-15875.)**2+(y1-22475.)**2<350**2 && amp[2] > 0.008","");
  ch.Draw("amp[2]>>h2(75,0,0.5)","((x1-15875.)**2+(y1-22475.)**2>350**2)&&x1>15375&&x1<16375&&y1>21975&&y1<22975 && amp[2] > 0.008","");
  h1->SetStats(0);
  h2->SetStats(0);
  h1->SetLineColor(2);
  h2->SetLineColor(1);
  h1->SetLineWidth(3);
  h2->SetLineWidth(3);
  h1->GetXaxis()->SetTitle("Amplitude [V]");
  h1->GetYaxis()->SetTitle("Number of Events");
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetYaxis()->SetLabelSize(0.04);
  h1->GetXaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.04);
  h1->GetXaxis()->SetTitleOffset(0.9);
  h1->GetYaxis()->SetTitleOffset(1.1);
  h1->GetYaxis()->SetLabelOffset(0.009);
  h1->GetXaxis()->SetRangeUser(0,0.25);
  h1->SetTitle("");

  h1->Draw();
  h2->Draw("same");

  TLegend *leg = new TLegend(0.35,0.7,0.9,0.9);
  leg->SetTextSize(0.05);
  leg->AddEntry(h1,"Center of the sensor");
  leg->AddEntry(h2,"Periphery of the sensor");
  leg->Draw();


  // TLatex *   tex1 = new TLatex(0.3, 0.95,"LGAD Sensor: CNM W11LGA35");
  // tex1->SetNDC();
  // tex1->SetTextSize(0.15);
  // tex1->Draw(); 


  c1->SaveAs("CNM_irradiated_amp_1D.C");
  c1->SaveAs("CNM_irradiated_amp_1D.pdf");

}

void IrradiatedSensorStudy_Occupancy_XY() {
  
  Make2DPlot_CNM();
  //Make1DPlot_CNM();
    
}
