void IrradiatedSensorStudy_TimeResolution_vs_X()
{
//=========Macro generated from canvas: c1/c
//=========  (Sat Aug  5 16:51:30 2017) by ROOT version6.08/02
  gROOT->Reset();
  TCanvas *c1 = new TCanvas("c1","multipads",800,400);
  gStyle->SetPadBorderMode(0);
  gStyle->SetFrameBorderMode(0);
  Float_t small = 0.002;
  Float_t large = 0.25;

  c1->Divide(1,2,small,small);
  c1->cd(1);
  gPad->SetBottomMargin(small);
  gPad->SetGridy();

   // TCanvas *c1 = new TCanvas("c1", "c",935,45,700,700);
   // c1->Range(9.481554,-1.333333,18.65545,111.1667);
   // c1->SetFillColor(0);
   // c1->SetBorderMode(0);
   // c1->SetBorderSize(2);
   // c1->SetGridy();
   // c1->SetFrameBorderMode(0);
   // c1->SetFrameBorderMode(0);
   // c1->SetLeftMargin(0.12);

   Double_t Graph0_fx1001[100] = {
   10,
   10.2,
   10.4,
   10.6,
   10.8,
   11,
   11.2,
   11.4,
   11.6,
   11.8,
   12,
   12.2,
   12.4,
   12.6,
   12.8,
   13,
   13.2,
   13.4,
   13.6,
   13.8,
   14,
   14.2,
   14.4,
   14.6,
   14.8,
   15,
   15.2,
   15.4,
   15.6,
   15.8,
   16,
   16.2,
   16.4,
   16.6,
   16.8,
   17,
   17.2,
   17.4,
   17.6,
   17.8,
   18,
   18.2,
   18.4,
   18.6,
   18.8,
   19,
   19.2,
   19.4,
   19.6,
   19.8,
   20,
   20.2,
   20.4,
   20.6,
   20.8,
   21,
   21.2,
   21.4,
   21.6,
   21.8,
   22,
   22.2,
   22.4,
   22.6,
   22.8,
   23,
   23.2,
   23.4,
   23.6,
   23.8,
   24,
   24.2,
   24.4,
   24.6,
   24.8,
   25,
   25.2,
   25.4,
   25.6,
   25.8,
   26,
   26.2,
   26.4,
   26.6,
   26.8,
   27,
   27.2,
   27.4,
   27.6,
   27.8,
   28,
   28.2,
   28.4,
   28.6,
   28.8,
   29,
   29.2,
   29.4,
   29.6,
   29.8};
   Double_t Graph0_fy1001[100] = {
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   36.81548,
   35.51559,
   33.1719,
   31.72654,
   33.93019,
   41.16386,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000};
   Double_t Graph0_fex1001[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   29.09496,
   1.844904,
   1.827607,
   1.579431,
   1.487439,
   1.710966,
   3.641784,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   TGraphErrors *gre = new TGraphErrors(100,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);
   gre->SetLineWidth(2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.1);
   
   TH1F *Graph_Graph_Graph30013001 = new TH1F("Graph_Graph_Graph30013001","",100,8.02,31.78);
   Graph_Graph_Graph30013001->SetMinimum(10);
   Graph_Graph_Graph30013001->SetMaximum(50);
   Graph_Graph_Graph30013001->SetDirectory(0);
   Graph_Graph_Graph30013001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph30013001->SetLineColor(ci);
   Graph_Graph_Graph30013001->GetXaxis()->SetTitle("x-coordinate [mm]");
   Graph_Graph_Graph30013001->GetXaxis()->SetRange(22,36);
   Graph_Graph_Graph30013001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013001->GetXaxis()->SetLabelSize(0.12);
   Graph_Graph_Graph30013001->GetXaxis()->SetTitleSize(0.15);
   Graph_Graph_Graph30013001->GetXaxis()->SetTitleOffset(0.87);
   Graph_Graph_Graph30013001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013001->GetYaxis()->SetTitle("Time Resolution [ps]");
   Graph_Graph_Graph30013001->GetYaxis()->SetNdivisions(503);
   Graph_Graph_Graph30013001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013001->GetYaxis()->SetLabelOffset(0.006);
   Graph_Graph_Graph30013001->GetYaxis()->SetLabelSize(0.10);
   Graph_Graph_Graph30013001->GetYaxis()->SetTitleSize(0.10);
   Graph_Graph_Graph30013001->GetYaxis()->SetTitleOffset(0.3);
   Graph_Graph_Graph30013001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph30013001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph30013001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph30013001);
  
   gre->Draw("ap");


   Double_t Graph0_fx1009[100] = {
   10,
   10.2,
   10.4,
   10.6,
   10.8,
   11,
   11.2,
   11.4,
   11.6,
   11.8,
   12,
   12.2,
   12.4,
   12.6,
   12.8,
   13,
   13.2,
   13.4,
   13.6,
   13.8,
   14,
   14.2,
   14.4,
   14.6,
   14.8,
   15,
   15.2,
   15.4,
   15.6,
   15.8,
   16,
   16.2,
   16.4,
   16.6,
   16.8,
   17,
   17.2,
   17.4,
   17.6,
   17.8,
   18,
   18.2,
   18.4,
   18.6,
   18.8,
   19,
   19.2,
   19.4,
   19.6,
   19.8,
   20,
   20.2,
   20.4,
   20.6,
   20.8,
   21,
   21.2,
   21.4,
   21.6,
   21.8,
   22,
   22.2,
   22.4,
   22.6,
   22.8,
   23,
   23.2,
   23.4,
   23.6,
   23.8,
   24,
   24.2,
   24.4,
   24.6,
   24.8,
   25,
   25.2,
   25.4,
   25.6,
   25.8,
   26,
   26.2,
   26.4,
   26.6,
   26.8,
   27,
   27.2,
   27.4,
   27.6,
   27.8,
   28,
   28.2,
   28.4,
   28.6,
   28.8,
   29,
   29.2,
   29.4,
   29.6,
   29.8};
   Double_t Graph0_fy1009[100] = {
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   115.185,
   30.77909,
   28.45984,
   32.77001,
   28.78389,
   27.17919,
   29.07161,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000};
   Double_t Graph0_fex1009[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1009[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   81.92965,
   3.465608,
   2.425312,
   3.46931,
   2.617983,
   2.315597,
   4.613944,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};

   TGraphErrors *gre1 = new TGraphErrors(100,Graph0_fx1009,Graph0_fy1009,Graph0_fex1009,Graph0_fey1009);
   gre1->SetName("Graph0");
   gre1->SetTitle("");
   gre1->SetFillColor(1);
   gre1->SetLineWidth(2);
   gre1->SetLineColor(kRed);
   gre1->SetMarkerColor(kRed);
   gre1->SetMarkerStyle(21);
   gre1->SetMarkerSize(1.1);
   
   TH1F *Graph_Graph_Graph30013002 = new TH1F("Graph_Graph_Graph30013002","",100,8.02,31.78);
   Graph_Graph_Graph30013002->SetMinimum(10);
   Graph_Graph_Graph30013002->SetMaximum(50);
   Graph_Graph_Graph30013002->SetDirectory(0);
   Graph_Graph_Graph30013002->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph30013002->SetLineColor(ci);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitle("x-coordinate [mm]");
   Graph_Graph_Graph30013002->GetXaxis()->SetRange(22,36);
   Graph_Graph_Graph30013002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013002->GetXaxis()->SetLabelSize(0.12);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitleSize(0.15);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitleOffset(0.87);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitle("Time Resolution [ps]");
   Graph_Graph_Graph30013002->GetYaxis()->SetNdivisions(503);
   Graph_Graph_Graph30013002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013002->GetYaxis()->SetLabelOffset(0.006);
   Graph_Graph_Graph30013002->GetYaxis()->SetLabelSize(0.12);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitleSize(0.10);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitleOffset(0.3);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph30013002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph30013002->GetZaxis()->SetTitleFont(42);
   gre1->SetHistogram(Graph_Graph_Graph30013002);
  
   gre1->Draw("p");



   TLatex *   tex1 = new TLatex(0.5, 0.75,"LGAD Sensor: HPK 50D");
   tex1->SetNDC();
   tex1->SetTextSize(0.15);
   tex1->Draw(); 

   TLegend *legend1 = new TLegend(0.50,0.28,0.85,0.60);
   legend1->SetTextSize(0.12);
   legend1->SetBorderSize(1);
   legend1->SetFillStyle(1001);
   legend1->AddEntry( gre, "Bias Voltage: 600V","LP");
   legend1->AddEntry( gre1, "Bias Voltage: 635V","LP");
   legend1->Draw();


   c1->cd(2);
   gPad->SetTopMargin(small);
   gPad->SetBottomMargin(large);
   gPad->SetGridy();
   

  
   Double_t Graph0_fx1001[100] = {
   10,
   10.2,
   10.4,
   10.6,
   10.8,
   11,
   11.2,
   11.4,
   11.6,
   11.8,
   12,
   12.2,
   12.4,
   12.6,
   12.8,
   13,
   13.2,
   13.4,
   13.6,
   13.8,
   14,
   14.2,
   14.4,
   14.6,
   14.8,
   15,
   15.2,
   15.4,
   15.6,
   15.8,
   16,
   16.2,
   16.4,
   16.6,
   16.8,
   17,
   17.2,
   17.4,
   17.6,
   17.8,
   18,
   18.2,
   18.4,
   18.6,
   18.8,
   19,
   19.2,
   19.4,
   19.6,
   19.8,
   20,
   20.2,
   20.4,
   20.6,
   20.8,
   21,
   21.2,
   21.4,
   21.6,
   21.8,
   22,
   22.2,
   22.4,
   22.6,
   22.8,
   23,
   23.2,
   23.4,
   23.6,
   23.8,
   24,
   24.2,
   24.4,
   24.6,
   24.8,
   25,
   25.2,
   25.4,
   25.6,
   25.8,
   26,
   26.2,
   26.4,
   26.6,
   26.8,
   27,
   27.2,
   27.4,
   27.6,
   27.8,
   28,
   28.2,
   28.4,
   28.6,
   28.8,
   29,
   29.2,
   29.4,
   29.6,
   29.8};
   Double_t Graph0_fy1001[100] = {
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   30.33119,
   37.74351,
   38.1419,
   42.71603,
   33.18153,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000};
   Double_t Graph0_fex1001[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   20.04963,
   1.475925,
   1.481192,
   1.820423,
   2.079997,
   2.244949,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   TGraphErrors *gre = new TGraphErrors(100,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);
   gre->SetLineWidth(2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.1);
   
   TH1F *Graph_Graph_Graph30013003 = new TH1F("Graph_Graph_Graph30013003","",100,8.02,31.78);
   Graph_Graph_Graph30013003->SetMinimum(20);
   Graph_Graph_Graph30013003->SetMaximum(70);
   Graph_Graph_Graph30013003->SetDirectory(0);
   Graph_Graph_Graph30013003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph30013003->SetLineColor(ci);
   Graph_Graph_Graph30013003->GetXaxis()->SetTitle("x-coordinate [mm]");
   Graph_Graph_Graph30013003->GetXaxis()->SetRange(22,36);
   Graph_Graph_Graph30013003->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013003->GetXaxis()->SetLabelSize(0.12);
   Graph_Graph_Graph30013003->GetXaxis()->SetTitleSize(0.15);
   Graph_Graph_Graph30013003->GetXaxis()->SetTitleOffset(0.75);
   Graph_Graph_Graph30013003->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013003->GetYaxis()->SetTitle("Time Resolution [ps]");
   Graph_Graph_Graph30013003->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013003->GetYaxis()->SetLabelSize(0.10);
   Graph_Graph_Graph30013003->GetYaxis()->SetTitleSize(0.10);
   Graph_Graph_Graph30013003->GetYaxis()->SetTitleOffset(0.30);
   Graph_Graph_Graph30013003->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013003->GetYaxis()->SetNdivisions(503);
   Graph_Graph_Graph30013003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph30013003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph30013003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph30013003);  
   gre->SetLineWidth(2);
   gre->Draw("ap");




   Double_t Graph0_fx1011[100] = {
   10,
   10.2,
   10.4,
   10.6,
   10.8,
   11,
   11.2,
   11.4,
   11.6,
   11.8,
   12,
   12.2,
   12.4,
   12.6,
   12.8,
   13,
   13.2,
   13.4,
   13.6,
   13.8,
   14,
   14.2,
   14.4,
   14.6,
   14.8,
   15,
   15.2,
   15.4,
   15.6,
   15.8,
   16,
   16.2,
   16.4,
   16.6,
   16.8,
   17,
   17.2,
   17.4,
   17.6,
   17.8,
   18,
   18.2,
   18.4,
   18.6,
   18.8,
   19,
   19.2,
   19.4,
   19.6,
   19.8,
   20,
   20.2,
   20.4,
   20.6,
   20.8,
   21,
   21.2,
   21.4,
   21.6,
   21.8,
   22,
   22.2,
   22.4,
   22.6,
   22.8,
   23,
   23.2,
   23.4,
   23.6,
   23.8,
   24,
   24.2,
   24.4,
   24.6,
   24.8,
   25,
   25.2,
   25.4,
   25.6,
   25.8,
   26,
   26.2,
   26.4,
   26.6,
   26.8,
   27,
   27.2,
   27.4,
   27.6,
   27.8,
   28,
   28.2,
   28.4,
   28.6,
   28.8,
   29,
   29.2,
   29.4,
   29.6,
   29.8};
   Double_t Graph0_fy1011[100] = {
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   0,
   19962.5,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   53580.93,
   29246.13,
   0,
   0,
   0,
   0,
   0,
   27188.58,
   41841.79,
   0,
   49.47247,
   42.16275,
   51.28964,
   47.08731,
   43.0336,
   0,
   0,
   40952.82,
   0,
   47455.65,
   3332.218,
   0,
   0,
   60850.43,
   0,
   26667.88,
   0,
   0,
   0,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000};
   Double_t Graph0_fex1011[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1011[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   11145.02,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   41893.74,
   22665.32,
   0,
   0,
   0,
   0,
   0,
   19385.15,
   26809.15,
   0,
   7.371917,
   2.600113,
   2.856897,
   3.314817,
   11.78532,
   0,
   0,
   30718.53,
   0,
   25339.98,
   2477.932,
   0,
   0,
   53711.79,
   0,
   20883.67,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};


   TGraphErrors *gre1 = new TGraphErrors(100,Graph0_fx1011,Graph0_fy1011,Graph0_fex1011,Graph0_fey1011);
   gre1->SetName("Graph0");
   gre1->SetTitle("");
   gre1->SetFillColor(1);
   gre1->SetLineColor(kRed);
   gre1->SetMarkerColor(kRed);
   gre1->SetLineWidth(2);
   gre1->SetMarkerStyle(21);
   gre1->SetMarkerSize(1.1);
   
   TH1F *Graph_Graph_Graph30013002 = new TH1F("Graph_Graph_Graph30013002","",100,8.02,31.78);
   Graph_Graph_Graph30013002->SetMinimum(20);
   Graph_Graph_Graph30013002->SetMaximum(70);
   Graph_Graph_Graph30013002->SetDirectory(0);
   Graph_Graph_Graph30013002->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph30013002->SetLineColor(ci);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitle("x-coordinate [mm]");
   Graph_Graph_Graph30013002->GetXaxis()->SetRange(22,36);
   Graph_Graph_Graph30013002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013002->GetXaxis()->SetLabelSize(0.12);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitleSize(0.15);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitleOffset(0.87);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitle("Time Resolution [ps]");
   Graph_Graph_Graph30013002->GetYaxis()->SetNdivisions(503);
   Graph_Graph_Graph30013002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013002->GetYaxis()->SetLabelOffset(0.006);
   Graph_Graph_Graph30013002->GetYaxis()->SetLabelSize(0.10);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitleSize(0.10);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitleOffset(0.3);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph30013002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph30013002->GetZaxis()->SetTitleFont(42);
   gre1->SetHistogram(Graph_Graph_Graph30013002);
  
   gre1->Draw("p");





   // c1->Modified();
   // c1->cd();
   // c1->SetSelected(c1);

   TLegend *legend = new TLegend(0.15,0.28,0.50,0.60);
   legend->SetTextSize(0.12);
   legend->SetBorderSize(1);
   legend->SetFillStyle(1001);
   legend->AddEntry( gre, "Bias Voltage: 400V","LP");
   legend->AddEntry( gre1, "Bias Voltage: 420V","LP");
   legend->Draw();

   TLatex *   tex2 = new TLatex(0.12, 0.86,"LGAD Sensor: CNM W11LGA35");
   tex2->SetNDC();
   tex2->SetTextSize(0.15);
   tex2->Draw(); 

   c1->Draw();
   c1->SaveAs("IrradiatedSensorStudy_TimeResolution_vs_X.pdf");
}
