TChain ch("pulse");
ch.Add("/eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/Skim/Run935_943_RECO_CH1CH2LGADSkim.root");
ch.Add("/eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/Skim/Run953-961_RECO_CH1CH2LGADSkim.root");
TCanvas *c1 = new TCanvas("c1","multipads",700,600);
ch.Draw("y1/1000.:x1/1000.>>h1(40,15.175, 16.575,40,21.775,23.175)","amp[2]*(x1/1000.>15.375&&x1/1000.<16.375&&y1/1000.>21.975&&y1/1000.<22.975)","colz");
h1->SetStats(0);
h1->SetTitle("");
h1->GetZaxis()->SetRangeUser(0,0.7);
h1->GetXaxis()->SetTitle("x-coordinate [mm]");
h1->GetYaxis()->SetTitle("y-coordinate [mm]");
h1->Draw("colz");
h1->GetXaxis()->SetTitleSize(0.045);
h1->GetYaxis()->SetTitleSize(0.045);
h1->GetYaxis()->SetTitleOffset(1.1);
h1->GetZaxis()->SetTitle("Amplitude [mV]");
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


TChain ch("pulse");
ch.Add("/eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/Skim/Run935_943_RECO_CH1CH2LGADSkim.root");
ch.Add("/eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/Skim/Run953-961_RECO_CH1CH2LGADSkim.root");
TCanvas *c1 = new TCanvas("c1","multipads",700,600);
c1->SetLeftMargin(0.12);
ch.Draw("amp[2]>>h1(75,0,0.5)","(x1-15875.)**2+(y1-22475.)**2<350**2","");
ch.Draw("amp[2]>>h2(75,0,0.5)","((x1-15875.)**2+(y1-22475.)**2>350**2)&&x1>15375&&x1<16375&&y1>21975&&y1<22975","");
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
h2->Draw("same")

TLegend *leg = new TLegend(0.6,0.7,0.9,0.9);
leg->SetTextSize(0.05);
leg->AddEntry(h1,"Center of the sensor");
leg->AddEntry(h2,"Periphery of the sensor");
leg->Draw()
