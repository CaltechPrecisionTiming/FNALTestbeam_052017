void MakeGap_HPKVsX() {

  TFile *_file1 = TFile::Open("eff_Channel1_Run638-781.root");
  TFile *_file2 = TFile::Open("eff_Channel2_Run638-781.root");
  
  TCanvas *c = new TCanvas("c","c",800,800);
  c->SetLeftMargin(0.13);
  c->SetRightMargin(0.05);

  TGraphAsymmErrors *g1 = (TGraphAsymmErrors*)_file1->Get("Efficiency_X");
  TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)_file2->Get("Efficiency_X");

  g1->SetMarkerSize(1.2);
  g2->SetMarkerSize(1.2);
  g1->SetMarkerColor(kBlue);
  g1->SetLineColor(kBlue);
  g2->SetMarkerColor(kRed);
  g2->SetLineColor(kRed);
  g1->SetLineWidth(2);
  g2->SetLineWidth(2);
  
  g1->GetXaxis()->SetLabelSize(0.04);
  g1->GetXaxis()->SetTitleSize(0.04);
  g1->GetXaxis()->SetLabelOffset(0.02);
  g1->GetXaxis()->SetTitleOffset(1.2);
  g1->GetYaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetTitleSize(0.05);
  g1->GetYaxis()->SetTitleOffset(1.1);


  c->Draw();

  g1->Draw("ap");
  g1->GetXaxis()->SetRangeUser(14.25,14.65);
  g2->Draw("p same");
  
  TF1 * f1 = new TF1("f1", "[0]*TMath::Erf(([1]-x)/[2])+[3]", 14.25, 14.65);
  f1->SetParameters(1., 14.45, 1, 0.);
  g1->Fit("f1","R");

  Double_t edge1 = f1->GetX(0.5);
  f1->SetLineColor(kBlue);
  f1->SetLineWidth(3);
  f1->Draw("same");
  std::cout<<edge1<<std::endl;

  TF1 * f2 = new TF1("f2", "[0]*TMath::Erf((x-[1])/[2])+[3]", 14.25, 14.65);
  f2->SetParameters(1., 14.55, 1, 0.);
  g2->Fit("f2","R");
  Double_t edge2 = f2->GetX(0.5);
  f2->SetLineColor(kRed);
  f2->SetLineWidth(3);
  f2->Draw("same");


  TArrow *ar3 = new TArrow(edge1,0.5,edge2,0.5,0.05,"<|>");
  ar3->SetAngle(35);
  ar3->SetLineWidth(2);
  ar3->SetArrowSize(0.03);
  ar3->SetLineColor(1);
  ar3->SetFillColor(1);
  ar3->Draw();

  TLatex *   tex = new TLatex(0.49, 0.5,Form("%4.0f #mum",round(100*(edge2-edge1))*10));
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw();

  TLatex *   tex1 = new TLatex(0.2, 0.94,"LGAD Sensor: HPK 50D-PIX");
  tex1->SetNDC();
  tex1->SetTextSize(0.05);
  tex1->Draw();  
  
  TLegend *leg = new TLegend(0.70,0.35,0.94,0.5,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(g1, "Channel 1", "LP");
   leg->AddEntry(g2, "Channel 2", "LP");
   leg->Draw();

   c->SaveAs("Eff_vs_X_HPK50DPIX_Ch1_2_fit.pdf");
   c->SaveAs("Eff_vs_X_HPK50DPIX_Ch1_2_fit.C");

}

void MakeGap_HPKVsX_UCSCBoard() {

  TFile *_file1 = TFile::Open("eff_Channel1_Run838+839+842.root");
  TFile *_file2 = TFile::Open("eff_Channel4_Run838+839+842.root");
  
  TCanvas *c = new TCanvas("c","c",800,800);
  c->SetLeftMargin(0.13);
  c->SetRightMargin(0.05);

  TGraphAsymmErrors *g1 = (TGraphAsymmErrors*)_file1->Get("Efficiency_X");
  TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)_file2->Get("Efficiency_X");

  g1->SetMarkerSize(1.2);
  g2->SetMarkerSize(1.2);
  g1->SetMarkerColor(kBlue);
  g1->SetLineColor(kBlue);
  g2->SetMarkerColor(kRed);
  g2->SetLineColor(kRed);
  g1->SetLineWidth(2);
  g2->SetLineWidth(2);
  
  g1->GetXaxis()->SetLabelSize(0.04);
  g1->GetXaxis()->SetTitleSize(0.04);
  g1->GetXaxis()->SetLabelOffset(0.02);
  g1->GetXaxis()->SetTitleOffset(1.2);
  g1->GetYaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetTitleSize(0.05);
  g1->GetYaxis()->SetTitleOffset(1.1);


  c->Draw();

  g1->Draw("ap");
  g1->GetXaxis()->SetRangeUser(13.55,13.9);
  g2->Draw("p same");
  
  TF1 * f1 = new TF1("f1", "[0]*TMath::Erf(([1]-x)/[2])+[3]", 13.5, 13.85);
  f1->SetParameters(1., 13.6, 1, 0.);
  g1->Fit("f1","R");

  Double_t edge1 = f1->GetX(0.5);
  f1->SetLineColor(kBlue);
  f1->SetLineWidth(3);
  f1->Draw("same");
  std::cout<<edge1<<std::endl;

  TF1 * f2 = new TF1("f2", "[0]*TMath::Erf((x-[1])/[2])+[3]", 13.5, 13.9);
  f2->SetParameters(1., 13.6, 1, 0.);
  g2->Fit("f2","R");
  Double_t edge2 = f2->GetX(0.5);
  f2->SetLineColor(kRed);
  f2->SetLineWidth(3);
  f2->Draw("same");


  TArrow *ar3 = new TArrow(edge1,0.5,edge2,0.5,0.05,"<|>");
  ar3->SetAngle(35);
  ar3->SetLineWidth(2);
  ar3->SetArrowSize(0.03);
  ar3->SetLineColor(1);
  ar3->SetFillColor(1);
  ar3->Draw();

  TLatex *   tex = new TLatex(0.47, 0.5,Form("%4.0f #mum",round(100*(edge2-edge1))*10));
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw();

  TLatex *   tex1 = new TLatex(0.2, 0.94,"LGAD Sensor: HPK 50C-PIX");
  tex1->SetNDC();
  tex1->SetTextSize(0.05);
  tex1->Draw();  
  
  TLegend *leg = new TLegend(0.70,0.35,0.94,0.5,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(g1, "Channel 1", "LP");
   leg->AddEntry(g2, "Channel 2", "LP");
   leg->Draw();

   c->SaveAs("Eff_vs_X_HPK50CPIX_Ch1_4_fit.pdf");
   c->SaveAs("Eff_vs_X_HPK50CPIX_Ch1_4_fit.C");

}



void MakeGap_HPKVsY() {

  TFile *_file1 = TFile::Open("eff_Channel3_Run838+839+842.root");
  TFile *_file2 = TFile::Open("eff_Channel4_Run838+839+842.root");
  
  TCanvas *c = new TCanvas("c","c",800,800);
  c->SetLeftMargin(0.13);
  c->SetRightMargin(0.05);

  TGraphAsymmErrors *g1 = (TGraphAsymmErrors*)_file1->Get("Efficiency_Y");
  TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)_file2->Get("Efficiency_Y");

  g1->SetMarkerSize(1.2);
  g2->SetMarkerSize(1.2);
  g1->SetMarkerColor(kBlue);
  g1->SetLineColor(kBlue);
  g2->SetMarkerColor(kRed);
  g2->SetLineColor(kRed);
  g1->SetLineWidth(2);
  g2->SetLineWidth(2);
  
  g1->GetXaxis()->SetLabelSize(0.04);
  g1->GetXaxis()->SetTitleSize(0.04);
  g1->GetXaxis()->SetLabelOffset(0.02);
  g1->GetXaxis()->SetTitleOffset(1.2);
  g1->GetYaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetTitleSize(0.05);
  g1->GetYaxis()->SetTitleOffset(1.1);

  c->Draw();

  g1->Draw("ap");
  g1->GetXaxis()->SetRangeUser(21.8,22.2);
  g2->Draw("p same");
  
  TF1 * f1 = new TF1("f1", "[0]*TMath::Erf(([1]-x)/[2])+[3]", 21.8, 22.2);
  f1->SetParameters(1., 22.05, 1, 0.);
  g1->Fit("f1","R");

  Double_t edge1 = f1->GetX(0.5);
  f1->SetLineColor(kBlue);
  f1->SetLineWidth(3);
  f1->Draw("same");
  std::cout<<edge1<<std::endl;

  TF1 * f2 = new TF1("f2", "[0]*TMath::Erf((x-[1])/[2])+[3]", 21.8, 22.2);
  f2->SetParameters(1., 22.05, 1, 0.);
  g2->Fit("f2","R");
  Double_t edge2 = f2->GetX(0.5);
  f2->SetLineColor(kRed);
  f2->SetLineWidth(3);
  f2->Draw("same");



  TArrow *ar3 = new TArrow(edge1,0.5,edge2,0.5,0.05,"<|>");
  ar3->SetAngle(35);
  ar3->SetLineWidth(2);
  ar3->SetArrowSize(0.03);
  ar3->SetLineColor(1);
  ar3->SetFillColor(1);
  ar3->Draw();

  TLatex *   tex = new TLatex(0.43, 0.5,Form("%4.0f #mum",round(100*(edge1-edge2))*10));
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw();

  TLatex *   tex1 = new TLatex(0.2, 0.94,"LGAD Sensor: HPK 50C-PIX");
  tex1->SetNDC();
  tex1->SetTextSize(0.05);
  tex1->Draw();  


  TLegend *leg = new TLegend(0.70,0.35,0.94,0.5,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(g1, "Channel 1", "LP");
   leg->AddEntry(g2, "Channel 3", "LP");
   leg->Draw();

   c->SaveAs("Eff_vs_Y_HPK50CPIX_Ch3_4_fit.pdf");
   c->SaveAs("Eff_vs_Y_HPK50CPIX_Ch3_4_fit.C");

}


void MakeGap_CNMVsX() {

  TFile *_file1 = TFile::Open("eff_Channel10_Run838+839+842.root");
  TFile *_file2 = TFile::Open("eff_Channel13_Run838+839+842.root");
  
  TCanvas *c = new TCanvas("c","c",800,800);
  c->SetLeftMargin(0.13);
  c->SetRightMargin(0.05);

  TGraphAsymmErrors *g1 = (TGraphAsymmErrors*)_file1->Get("Efficiency_X");
  TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)_file2->Get("Efficiency_X");

  g1->SetMarkerSize(1.2);
  g2->SetMarkerSize(1.2);
  g1->SetMarkerColor(kBlue);
  g1->SetLineColor(kBlue);
  g2->SetMarkerColor(kRed);
  g2->SetLineColor(kRed);
  g1->SetLineWidth(2);
  g2->SetLineWidth(2);
  
  g1->GetXaxis()->SetLabelSize(0.04);
  g1->GetXaxis()->SetTitleSize(0.04);
  g1->GetXaxis()->SetLabelOffset(0.02);
  g1->GetXaxis()->SetTitleOffset(1.2);
  g1->GetYaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetTitleSize(0.05);
  g1->GetYaxis()->SetTitleOffset(1.1);


  // gStyle->SetPalette(1); //kBird

  c->Draw();

  g1->Draw("ap");
  g1->GetXaxis()->SetRangeUser(14.8,15.25);
  g2->Draw("p same");
  
  TF1 * f1 = new TF1("f1", "[0]*TMath::Erf(([1]-x)/[2])+[3]", 14.8, 15.2);
  f1->SetParameters(1., 15., 1, 0.);
  g1->Fit("f1","R");

  Double_t edge1 = f1->GetX(0.5);
  std::cout<<edge1<<std::endl;
  f1->SetLineColor(kBlue);
  f1->SetLineWidth(3);
  f1->Draw("same");

  TF1 * f2 = new TF1("f2", "[0]*TMath::Erf((x-[1])/[2])+[3]", 14.83, 15.3);
  f2->SetParameters(1., 15.08, 1, 0.);
  g2->Fit("f2","R");
  Double_t edge2 = f2->GetX(0.5);
  f2->SetLineColor(kRed);
  f2->SetLineWidth(3);
  f2->Draw("same");


  TArrow *ar3 = new TArrow(edge1,0.5,edge2,0.5,0.05,"<|>");
  ar3->SetAngle(35);
  ar3->SetLineWidth(2);
  ar3->SetArrowSize(0.03);
  ar3->SetLineColor(1);
  ar3->SetFillColor(1);
  ar3->Draw();

  TLatex *   tex = new TLatex(0.50, 0.5,Form("%4.0f#mum",round(100*(edge2-edge1))*10));
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw();

  TLatex *   tex1 = new TLatex(0.2, 0.94,"LGAD Sensor: CNM W9HG11");
  tex1->SetNDC();
  tex1->SetTextSize(0.05);
  tex1->Draw();  
  
  TLegend *leg = new TLegend(0.68,0.35,0.94,0.5,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(g1, "Channel 1", "LP");
   leg->AddEntry(g2, "Channel 2", "LP");
   leg->Draw();

   c->SaveAs("Eff_vs_X_CNM_Ch10_13_fit.pdf");
   c->SaveAs("Eff_vs_X_CNM_Ch10_13_fit.C");

}

void MakeGap_CNMVsY() {

  TFile *_file1 = TFile::Open("eff_Channel13_Run838+839+842.root");
  TFile *_file2 = TFile::Open("eff_Channel12_Run838+839+842.root");
  
  TCanvas *c = new TCanvas("c","c",800,800);
  c->SetLeftMargin(0.13);
  c->SetRightMargin(0.05);

  TGraphAsymmErrors *g1 = (TGraphAsymmErrors*)_file1->Get("Efficiency_Y");
  TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)_file2->Get("Efficiency_Y");


  g1->SetMarkerSize(1.2);
  g2->SetMarkerSize(1.2);
  g1->SetMarkerColor(kBlue);
  g1->SetLineColor(kBlue);
  g2->SetMarkerColor(kRed);
  g2->SetLineColor(kRed);
  g1->SetLineWidth(2);
  g2->SetLineWidth(2);
  
  g1->GetXaxis()->SetLabelSize(0.04);
  g1->GetXaxis()->SetTitleSize(0.04);
  g1->GetXaxis()->SetLabelOffset(0.02);
  g1->GetXaxis()->SetTitleOffset(1.2);
  g1->GetYaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetTitleSize(0.05);
  g1->GetYaxis()->SetTitleOffset(1.1);

  // gStyle->SetPalette(1); //kBird

  c->Draw();

  g1->Draw("ap");
  g1->GetXaxis()->SetRangeUser(22.4,22.8);
  g2->Draw("p same");
  
  TF1 * f1 = new TF1("f1", "[0]*TMath::Erf(([1]-x)/[2])+[3]", 22.3, 22.9);
  f1->SetParameters(1., 23.0, 1, 0.);
  g1->Fit("f1","R");

  Double_t edge1 = f1->GetX(0.5);
  std::cout<<edge1<<std::endl;
  f1->SetLineColor(kBlue);
  f1->SetLineWidth(3);
  f1->Draw("same");

  TF1 * f2 = new TF1("f2", "[0]*TMath::Erf((x-[1])/[2])+[3]", 22.32, 22.88);
  f2->SetParameters(1., 22.6, 1, 0.);
  g2->Fit("f2","R");
  Double_t edge2 = f2->GetX(0.5);
  f2->SetLineColor(kRed);
  f2->SetLineWidth(3);
  f2->Draw("same");


  TArrow *ar3 = new TArrow(edge1,0.5,edge2,0.5,0.05,"<|>");
  ar3->SetAngle(35);
  ar3->SetLineWidth(2);
  ar3->SetArrowSize(0.03);
  ar3->SetLineColor(1);
  ar3->SetFillColor(1);
  ar3->Draw();

  TLatex *   tex = new TLatex(0.47, 0.5,Form("%4.0f#mum",round(100*(edge2-edge1))*10));
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw();

  TLatex *   tex1 = new TLatex(0.2, 0.94,"LGAD Sensor: CNM W9HG11");
  tex1->SetNDC();
  tex1->SetTextSize(0.05);
  tex1->Draw();  

  TLegend *leg = new TLegend(0.68,0.35,0.94,0.5,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(g1, "Channel 1", "LP");
   leg->AddEntry(g2, "Channel 3", "LP");
   leg->Draw();

   c->SaveAs("Eff_vs_Y_CNM_Ch13_12_fit.pdf");
   c->SaveAs("Eff_vs_Y_CNM_Ch13_12_fit.C");
  
}



void plotLGADGaps () {

  MakeGap_HPKVsX();
  MakeGap_HPKVsX_UCSCBoard();
  MakeGap_HPKVsY();
  MakeGap_CNMVsX();
  MakeGap_CNMVsY();

}
