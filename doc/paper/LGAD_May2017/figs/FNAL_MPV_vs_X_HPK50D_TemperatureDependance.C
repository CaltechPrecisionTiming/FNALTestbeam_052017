void FNAL_MPV_vs_X_HPK50D_TemperatureDependance()
{
//=========Macro generated from canvas: c1/c
//=========  (Sat Aug  5 16:51:30 2017) by ROOT version6.08/02
   TCanvas *c1 = new TCanvas("c1", "c",935,45,700,700);
   c1->Range(9.481554,-1.333333,18.65545,111.1667);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridy();
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   c1->SetLeftMargin(0.15);

   Double_t Graph0_fx1001[80] = {
   10,
   10.25,
   10.5,
   10.75,
   11,
   11.25,
   11.5,
   11.75,
   12,
   12.25,
   12.5,
   12.75,
   13,
   13.25,
   13.5,
   13.75,
   14,
   14.25,
   14.5,
   14.75,
   15,
   15.25,
   15.5,
   15.75,
   16,
   16.25,
   16.5,
   16.75,
   17,
   17.25,
   17.5,
   17.75,
   18,
   18.25,
   18.5,
   18.75,
   19,
   19.25,
   19.5,
   19.75,
   20,
   20.25,
   20.5,
   20.75,
   21,
   21.25,
   21.5,
   21.75,
   22,
   22.25,
   22.5,
   22.75,
   23,
   23.25,
   23.5,
   23.75,
   24,
   24.25,
   24.5,
   24.75,
   25,
   25.25,
   25.5,
   25.75,
   26,
   26.25,
   26.5,
   26.75,
   27,
   27.25,
   27.5,
   27.75,
   28,
   28.25,
   28.5,
   28.75,
   29,
   29.25,
   29.5,
   29.75};
   Double_t Graph0_fy1001[80] = {
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,   
   -999000, //0.02119885,//From CH3
   0.02131358,
   0.02138817,
   0.02135411,
   0.02005799,
   0.02123458,
   0.02080814,
   0.02101068,
   0.02100601,
   0.02040529,
   0.02025564,//From CH6
   0.02082824,
   0.02110887,
   0.0207798,
   0.02108095,
   0.02060765,
   0.02053128,
   0.02058454,
   0.02096276,
   0.02093581,
   0.02138054,
   -999000, //0.01970978,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
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
   Double_t Graph0_fex1001[80] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fey1001[80] = {
   0,
   0,
   0,
   0,
   0,
   0.0005372065, //From CH3
   0.0006616075,
   0.0003950147,
   0.0003473615,
   0.0005086461,
   0.0003322771,
   0.0002827847,
   0.0002886568,
   0.000612459,
   0.000648393,
   0.0005240954, //From CH6
   0.000273983,
   0.0003128747,
   0.0002796586,
   0.0002859282,
   0.0002931263,
   0.000309195,
   0.0003180768,
   0.0003088703,
   0.000323099,
   0.0003478551,
   0.0007665883,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   TGraphErrors *gre1 = new TGraphErrors(80,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre1->SetName("Graph0");
   gre1->SetTitle("");
   gre1->SetFillColor(1);
   gre1->SetLineColor(kRed);
   gre1->SetLineWidth(2);
   gre1->SetMarkerColor(kRed);
   gre1->SetMarkerStyle(21);
   gre1->SetMarkerSize(1.3);
   
   TH1F *Graph_Graph_Graph10191001 = new TH1F("Graph_Graph_Graph10191001","",100,8.025,31.725);
   Graph_Graph_Graph10191001->SetMinimum(0);
   Graph_Graph_Graph10191001->SetMaximum(0.06);
   Graph_Graph_Graph10191001->SetDirectory(0);
   Graph_Graph_Graph10191001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10191001->SetLineColor(ci);
   Graph_Graph_Graph10191001->GetXaxis()->SetTitle("x-coordinate [mm]");
   Graph_Graph_Graph10191001->GetXaxis()->SetRange(11,41);
   Graph_Graph_Graph10191001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10191001->GetXaxis()->SetLabelSize(0.04);
   Graph_Graph_Graph10191001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph10191001->GetXaxis()->SetTitleOffset(0.87);
   Graph_Graph_Graph10191001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph10191001->GetYaxis()->SetTitle("MIP MPV[V]");
   Graph_Graph_Graph10191001->GetYaxis()->SetNdivisions(508);
   Graph_Graph_Graph10191001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10191001->GetYaxis()->SetLabelOffset(0.006);
   Graph_Graph_Graph10191001->GetYaxis()->SetLabelSize(0.04);
   Graph_Graph_Graph10191001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph10191001->GetYaxis()->SetTitleOffset(1.3);
   Graph_Graph_Graph10191001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph10191001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10191001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph10191001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph10191001->GetZaxis()->SetTitleFont(42);
   gre1->SetHistogram(Graph_Graph_Graph10191001);
  
  
   gre1->Draw("ap");
   
   Double_t Graph0_fx1002[80] = {
   10,
   10.25,
   10.5,
   10.75,
   11,
   11.25,
   11.5,
   11.75,
   12,
   12.25,
   12.5,
   12.75,
   13,
   13.25,
   13.5,
   13.75,
   14,
   14.25,
   14.5,
   14.75,
   15,
   15.25,
   15.5,
   15.75,
   16,
   16.25,
   16.49045,
   16.73994,
   17,
   17.25,
   17.5,
   17.75,
   18,
   18.25,
   18.5,
   18.75,
   19,
   19.25,
   19.5,
   19.75,
   20,
   20.25,
   20.5,
   20.75,
   21,
   21.25,
   21.5,
   21.75,
   22,
   22.25,
   22.5,
   22.75,
   23,
   23.25,
   23.5,
   23.75,
   24,
   24.25,
   24.5,
   24.75,
   25,
   25.25,
   25.5,
   25.75,
   26,
   26.25,
   26.5,
   26.75,
   27,
   27.25,
   27.5,
   27.75,
   28,
   28.25,
   28.5,
   28.75,
   29,
   29.25,
   29.5,
   29.75};
   Double_t Graph0_fy1002[80] = {
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000, 
    0.03622481, //From CH3
   0.03698687,
   0.03665039,
   0.03657636,
   0.0371275,
   0.03711186,
   0.03763556,
   0.03586905,
   0.0374268,
   0.03654179,
   0.0369738,
   -999000, //From CH6
   0.03602783,
   0.0356961,
   0.03566665,
   0.03673138,
   0.03598856,
   0.0355481,
   0.03472997,
   0.03530267,
   -999000, //0.03582111,
   -999000, //0.03487616,
   -999000, //0.03548032,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
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
   Double_t Graph0_fex1002[80] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fey1002[80] = {
   0,
   0,
   0,
   0,
   0,
   0, 
   0.0007006451, //From CH3
   0.0006181325,
   0.0005803183,
   0.0005705021,
   0.000617267,
   0.0005460363,
   0.0003671185,
   0.0005112871,
   0.0005228325,
   0.0005288108,
   0.0005143245,
   0,  
   0.0005215867, //From CH6
   0.000560978,
   0.0005853833,
   0.0006015598,
   0.0005865517,
   0.0004935694,
   0.0007967009,
   0.0006436401,
   0.0006305927,
   0.0005605717,
   0.0005907792,
   0, 
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   gre2 = new TGraphErrors(80,Graph0_fx1002,Graph0_fy1002,Graph0_fex1002,Graph0_fey1002);
   gre2->SetName("Graph0");
   gre2->SetTitle("");
   gre2->SetFillColor(1);
   gre2->SetLineColor(kBlue);
   gre2->SetLineWidth(2);

   ci = 1180;
   color = new TColor(ci, 1, 0, 0, " ", 0.988);
   gre2->SetMarkerColor(kBlue);
   gre2->SetMarkerStyle(20);
   gre2->SetMarkerSize(1.3);
   
   TH1F *Graph_Graph_Graph10191002 = new TH1F("Graph_Graph_Graph10191002","",100,8.025,31.725);
   Graph_Graph_Graph10191002->SetMinimum(0);
   Graph_Graph_Graph10191002->SetMaximum(0.2);
   Graph_Graph_Graph10191002->SetDirectory(0);
   Graph_Graph_Graph10191002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10191002->SetLineColor(ci);
   Graph_Graph_Graph10191002->GetXaxis()->SetTitle("x-coordinate [mm]");
   Graph_Graph_Graph10191002->GetXaxis()->SetRange(11,43);
   Graph_Graph_Graph10191002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10191002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph10191002->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph10191002->GetXaxis()->SetTitleOffset(0.87);
   Graph_Graph_Graph10191002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph10191002->GetYaxis()->SetTitle("MIP MPV [V]");
   Graph_Graph_Graph10191002->GetYaxis()->SetNdivisions(508);
   Graph_Graph_Graph10191002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10191002->GetYaxis()->SetLabelSize(0.1);
   Graph_Graph_Graph10191002->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph10191002->GetYaxis()->SetTitleOffset(0.4);
   Graph_Graph_Graph10191002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph10191002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10191002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph10191002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph10191002->GetZaxis()->SetTitleFont(42);
   gre2->SetHistogram(Graph_Graph_Graph10191002);
   gre2->SetLineWidth(2);
   gre2->Draw("P");
   




   Double_t Graph0_fx1003[80] = {
   10,
   10.25,
   10.5,
   10.75,
   11,
   11.25,
   11.5,
   11.75,
   12,
   12.25,
   12.5,
   12.75,
   13,
   13.25,
   13.5,
   13.75,
   14,
   14.25,
   14.5,
   14.75,
   15,
   15.25,
   15.5,
   15.75,
   16,
   16.25,
   16.4881,
   16.75,
   17,
   17.25,
   17.5,
   17.75,
   18,
   18.25,
   18.5,
   18.75,
   19,
   19.25,
   19.5,
   19.75,
   20,
   20.25,
   20.5,
   20.75,
   21,
   21.25,
   21.5,
   21.75,
   22,
   22.25,
   22.5,
   22.75,
   23,
   23.25,
   23.5,
   23.75,
   24,
   24.25,
   24.5,
   24.75,
   25,
   25.25,
   25.5,
   25.75,
   26,
   26.25,
   26.5,
   26.75,
   27,
   27.25,
   27.5,
   27.75,
   28,
   28.25,
   28.5,
   28.75,
   29,
   29.25,
   29.5,
   29.75};
   Double_t Graph0_fy1003[80] = {
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000, 
   0.04490917, //From CH3
   0.04489682,
   0.04568254,
   0.04449178,
   0.04489455,
   0.04510586,
   0.04451507,
   0.04540418,
   0.04569308,
   0.0443738,
   0.04578292,
   0.04094254,
   0.04370395, //From CH6
   0.0424765,
   0.0436025,
   0.04333359,
   0.04237392,
   0.04330594,
   0.0427251,
   0.04406836,
   -999000, //0.04367307,
   -999000, //0.04416776,
   -999000, //0.04498279,
   -999000, //0.04262496,
   -999000, 
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
   -999000,
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
   Double_t Graph0_fex1003[80] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph0_fey1003[80] = {
   0,
   0,
   0,
   0,
   0,
   0, 
   0.0005933588, //From CH3
   0.0004872624,
   0.0005268794,
   0.0008699342,
   0.0004245599,
   0.0005032751,
   0.0005371889,
   0.0005570892,
   0.0005416767,
   0.0004009563,
   0.0004456569,
   0.0006731426,
   0.0004062247, //From CH6
   0.0005089457,
   0.0006041199,
   0.0004082531,
   0.0005273509,
   0.0006251687,
   0.0006016776,
   0.0006360853,
   0.0008484018,
   0.0007089435,
   0.0007466021,
   0.001071562,
   0, 
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   gre3 = new TGraphErrors(80,Graph0_fx1003,Graph0_fy1003,Graph0_fex1003,Graph0_fey1003);
   gre3->SetName("Graph0");
   gre3->SetTitle("");
   gre3->SetFillColor(1);
   gre3->SetLineWidth(2);
   gre3->SetLineColor(kViolet);
   gre3->SetMarkerColor(kViolet);
   gre3->SetMarkerStyle(34);
   gre3->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph_Graph10191003 = new TH1F("Graph_Graph_Graph10191003","",100,8.025,31.725);
   Graph_Graph_Graph10191003->SetMinimum(0);
   Graph_Graph_Graph10191003->SetMaximum(0.2);
   Graph_Graph_Graph10191003->SetDirectory(0);
   Graph_Graph_Graph10191003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10191003->SetLineColor(ci);
   Graph_Graph_Graph10191003->GetXaxis()->SetTitle("x-coordinate [mm]");
   Graph_Graph_Graph10191003->GetXaxis()->SetRange(11,43);
   Graph_Graph_Graph10191003->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10191003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph10191003->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph10191003->GetXaxis()->SetTitleOffset(0.87);
   Graph_Graph_Graph10191003->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph10191003->GetYaxis()->SetTitle("Time resolution [ps]");
   Graph_Graph_Graph10191003->GetYaxis()->SetNdivisions(508);
   Graph_Graph_Graph10191003->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10191003->GetYaxis()->SetLabelSize(0.1);
   Graph_Graph_Graph10191003->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph10191003->GetYaxis()->SetTitleOffset(0.4);
   Graph_Graph_Graph10191003->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph10191003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10191003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph10191003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph10191003->GetZaxis()->SetTitleFont(42);
   gre3->SetHistogram(Graph_Graph_Graph10191003);
   
   gre3->Draw("P");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);

   TLegend *legend = new TLegend(0.60,0.75,0.90,0.90);
   legend->SetTextSize(0.035);
   legend->SetBorderSize(1);
   legend->SetFillStyle(1001);
   legend->AddEntry( gre1, "20 degrees C","LP");
   legend->AddEntry( gre2, "-10 degrees C","LP");
   legend->AddEntry( gre3, "-20 degrees C","LP");
   legend->Draw();

   TLatex *   tex = new TLatex(0.165, 0.93,"LGAD Sensor: HPK 50D-PIX");
   tex->SetNDC();
   tex->SetTextSize(0.05);
   tex->Draw(); 

   c1->SaveAs("FNAL_MPV_vs_X_HPK50D_TemperatureDependance.pdf");
}
