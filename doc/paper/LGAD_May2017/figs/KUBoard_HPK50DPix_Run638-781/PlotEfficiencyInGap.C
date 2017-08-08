void PlotEfficiencyInGap() {

  TFile *f1 = TFile::Open("eff_Channel1.root","READ");
  TFile *f2 = TFile::Open("eff_Channel2.root","READ");

  TGraphAsymmErrors *effGraph1 = (TGraphAsymmErrors *)f1->Get("Efficiency_X");
  TGraphAsymmErrors *effGraph2 = (TGraphAsymmErrors *)f2->Get("Efficiency_X");

  TCanvas *cv = new TCanvas("Cv","Cv", 800,800);
  cv->SetLeftMargin(0.13);
  cv->SetBottomMargin(0.12);
  cv->SetRightMargin(0.05);

  effGraph1->Draw("ap");
  effGraph2->Draw("p");
  effGraph1->SetMarkerColor(kRed);
  effGraph1->SetLineColor(kRed);
  effGraph1->SetLineWidth(2);
  effGraph2->SetMarkerColor(kBlue);
  effGraph2->SetLineColor(kBlue);
  effGraph2->SetLineWidth(2);
  effGraph1->GetXaxis()->SetRangeUser(14.3,14.65);
  effGraph1->GetXaxis()->SetLabelSize(0.04);
  effGraph1->GetXaxis()->SetLabelOffset(0.02);
  effGraph1->GetXaxis()->SetTitleSize(0.05);
  effGraph1->GetXaxis()->SetTitleOffset(1.1);
  effGraph1->GetYaxis()->SetLabelSize(0.04);
  effGraph1->GetYaxis()->SetTitleSize(0.05);
  effGraph1->GetYaxis()->SetTitleOffset(1.1);

  TLegend *legend = new TLegend(0.73,0.35,0.92,0.50);
  legend->SetTextSize(0.04);
  legend->SetLineWidth(2);
  legend->SetBorderSize(1);
  legend->SetFillStyle(1001);
  legend->AddEntry( effGraph1, "Pixel 1","LP");
  legend->AddEntry( effGraph2, "Pixel 2","LP");
  legend->Draw();
  
  TLatex *   tex = new TLatex(0.2, 0.93,"LGAD Sensor: HPK 50D-PIX");
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw(); 
  
   cv->SaveAs("EfficiencyInGap_HPK50DPix.pdf");
   cv->SaveAs("EfficiencyInGap_HPK50DPix.C");
}
