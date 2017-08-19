void MakeGap_HPK() {

  TFile *_file1 = TFile::Open("Eff_vs_X_Ch1.root");
  TFile *_file2 = TFile::Open("Eff_vs_X_Ch4.root");
  
  TCanvas *c = new TCanvas("c","c",700,600);
  c->SetLeftMargin(0.13);
  c->SetRightMargin(0.18);

  TCanvas *c1 = (TCanvas*)_file1->Get("canvas");
  TCanvas *c2 = (TCanvas*)_file2->Get("canvas");
  TGraphAsymmErrors *g1 = (TGraphAsymmErrors*)c1->GetPrimitive("Graph0");
  TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)c2->GetPrimitive("Graph0");

  g2->SetMarkerColor(2);
  g2->SetLineColor(2);

  // gStyle->SetPalette(1); //kBird

  c->Draw();

  g1->Draw("ap");
  g1->GetXaxis()->SetRangeUser(13.55,13.9);
  g2->Draw("p same");
  
  TF1 * f1 = new TF1("f1", "[0]*TMath::Erf(([1]-x)/[2])+[3]", 13.5, 13.85);
  f1->SetParameters(1., 13.6, 1, 0.);
  g1->Fit("f1","R");

  Double_t edge1 = f1->GetX(0.5);
  std::cout<<edge1<<std::endl;

  TF1 * f2 = new TF1("f2", "[0]*TMath::Erf((x-[1])/[2])+[3]", 13.5, 13.9);
  f2->SetParameters(1., 13.6, 1, 0.);
  g2->Fit("f2","R");
  Double_t edge2 = f2->GetX(0.5);


  TArrow *ar3 = new TArrow(edge1,0.5,edge2,0.5,0.05,"<|>");
  ar3->SetAngle(35);
  ar3->SetLineWidth(2);
  ar3->SetArrowSize(0.03);
  ar3->SetLineColor(1);
  ar3->SetFillColor(1);
  ar3->Draw();

  TLatex *   tex = new TLatex(0.41, 0.5,Form("%4.2f #mum",1000*(edge2-edge1)));
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw();

  TLatex *   tex1 = new TLatex(0.2, 0.94,"LGAD Sensor: HPK 50D-PIX");
  tex1->SetNDC();
  tex1->SetTextSize(0.05);
  tex1->Draw();  
  
}

void MakeGap_HPKY() {

  TFile *_file1 = TFile::Open("Eff_vs_Y_Ch3.root");
  TFile *_file2 = TFile::Open("Eff_vs_Y_Ch4.root");
  
  TCanvas *c = new TCanvas("c","c",700,600);
  c->SetLeftMargin(0.13);
  c->SetRightMargin(0.18);

  TCanvas *c1 = (TCanvas*)_file1->Get("canvas");
  TCanvas *c2 = (TCanvas*)_file2->Get("canvas");
  TGraphAsymmErrors *g1 = (TGraphAsymmErrors*)c1->GetPrimitive("Graph0");
  TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)c2->GetPrimitive("Graph0");

  g2->SetMarkerColor(2);
  g2->SetLineColor(2);

  // gStyle->SetPalette(1); //kBird

  c->Draw();

  g1->Draw("ap");
  g1->GetXaxis()->SetRangeUser(21.8,22.2);
  g2->Draw("p same");
  
  TF1 * f1 = new TF1("f1", "[0]*TMath::Erf(([1]-x)/[2])+[3]", 21.9, 22.2);
  f1->SetParameters(1., 22., 1, 0.);
  g1->Fit("f1","R");

  Double_t edge1 = f1->GetX(0.5);
  std::cout<<edge1<<std::endl;

  TF1 * f2 = new TF1("f2", "[0]*TMath::Erf((x-[1])/[2])+[3]", 21.8, 22.1);
  f2->SetParameters(1., 22., 1, 0.);
  g2->Fit("f2","R");
  Double_t edge2 = f2->GetX(0.5);


  TArrow *ar3 = new TArrow(edge1,0.5,edge2,0.5,0.05,"<|>");
  ar3->SetAngle(35);
  ar3->SetLineWidth(2);
  ar3->SetArrowSize(0.03);
  ar3->SetLineColor(1);
  ar3->SetFillColor(1);
  ar3->Draw();

  TLatex *   tex = new TLatex(0.41, 0.5,Form("%4.2f #mum",1000*(edge1-edge2)));
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw();

  TLatex *   tex1 = new TLatex(0.2, 0.94,"LGAD Sensor: HPK 50D-PIX");
  tex1->SetNDC();
  tex1->SetTextSize(0.05);
  tex1->Draw();  
  
}


void MakeGap_CNM() {

  TFile *_file1 = TFile::Open("Eff_vs_X_Ch10.root");
  TFile *_file2 = TFile::Open("Eff_vs_X_Ch13.root");
  
  TCanvas *c = new TCanvas("c","c",700,600);
  c->SetLeftMargin(0.13);
  c->SetRightMargin(0.18);

  TCanvas *c1 = (TCanvas*)_file1->Get("canvas");
  TCanvas *c2 = (TCanvas*)_file2->Get("canvas");
  TGraphAsymmErrors *g1 = (TGraphAsymmErrors*)c1->GetPrimitive("Graph0");
  TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)c2->GetPrimitive("Graph0");

  g2->SetMarkerColor(2);
  g2->SetLineColor(2);

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

  TF1 * f2 = new TF1("f2", "[0]*TMath::Erf((x-[1])/[2])+[3]", 14.83, 15.3);
  f2->SetParameters(1., 15., 1, 0.);
  g2->Fit("f2","R");
  Double_t edge2 = f2->GetX(0.5);


  TArrow *ar3 = new TArrow(edge1,0.5,edge2,0.5,0.05,"<|>");
  ar3->SetAngle(35);
  ar3->SetLineWidth(2);
  ar3->SetArrowSize(0.03);
  ar3->SetLineColor(1);
  ar3->SetFillColor(1);
  ar3->Draw();

  TLatex *   tex = new TLatex(0.41, 0.5,Form("%4.2f #mum",1000*(edge2-edge1)));
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw();

  TLatex *   tex1 = new TLatex(0.2, 0.94,"LGAD Sensor: CNM W9HG11");
  tex1->SetNDC();
  tex1->SetTextSize(0.05);
  tex1->Draw();  
  
}

void MakeGap_CNMY() {

  TFile *_file1 = TFile::Open("Eff_vs_Y_Ch13.root");
  TFile *_file2 = TFile::Open("Eff_vs_Y_Ch12.root");
  
  TCanvas *c = new TCanvas("c","c",700,600);
  c->SetLeftMargin(0.13);
  c->SetRightMargin(0.18);

  TCanvas *c1 = (TCanvas*)_file1->Get("canvas");
  TCanvas *c2 = (TCanvas*)_file2->Get("canvas");
  TGraphAsymmErrors *g1 = (TGraphAsymmErrors*)c1->GetPrimitive("Graph0");
  TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)c2->GetPrimitive("Graph0");

  g2->SetMarkerColor(2);
  g2->SetLineColor(2);

  // gStyle->SetPalette(1); //kBird

  c->Draw();

  g1->Draw("ap");
  g1->GetXaxis()->SetRangeUser(22.4,22.8);
  g2->Draw("p same");
  
  TF1 * f1 = new TF1("f1", "[0]*TMath::Erf(([1]-x)/[2])+[3]", 22.3, 22.9);
  f1->SetParameters(1., 22.6, 1, 0.);
  g1->Fit("f1","R");

  Double_t edge1 = f1->GetX(0.5);
  std::cout<<edge1<<std::endl;

  TF1 * f2 = new TF1("f2", "[0]*TMath::Erf((x-[1])/[2])+[3]", 22.32, 22.88);
  f2->SetParameters(1., 22.6, 1, 0.);
  g2->Fit("f2","R");
  Double_t edge2 = f2->GetX(0.5);


  TArrow *ar3 = new TArrow(edge1,0.5,edge2,0.5,0.05,"<|>");
  ar3->SetAngle(35);
  ar3->SetLineWidth(2);
  ar3->SetArrowSize(0.03);
  ar3->SetLineColor(1);
  ar3->SetFillColor(1);
  ar3->Draw();

  TLatex *   tex = new TLatex(0.41, 0.5,Form("%4.2f #mum",1000*(edge2-edge1)));
  tex->SetNDC();
  tex->SetTextSize(0.05);
  tex->Draw();

  TLatex *   tex1 = new TLatex(0.2, 0.94,"LGAD Sensor: CNM W9HG11");
  tex1->SetNDC();
  tex1->SetTextSize(0.05);
  tex1->Draw();  
  
}



